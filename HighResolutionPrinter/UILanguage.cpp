#include "UILanguage.h"
#include <QTextCodec>
#include "xml\tinyxml.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanageform.h"
#include "ui_filemanageform.h"
#include "paramsettingform.h"
#include "ui_paramsettingform.h"

CUILanguage::CUILanguage(QObject* pMainwindow)
{
	m_pMainwindow = pMainwindow;


}


CUILanguage::~CUILanguage(void)
{
}

void CUILanguage::ChangeLanguage(int nLanguageType)
{
	MainWindow* pMainwindow = (MainWindow*)(m_pMainwindow);
	char strFileName[100];

	//根据nLanguageType 读取相应的xml文件
	if(nLanguageType == 1)
		sprintf(strFileName,"%s","System\\chinese.xml");
	if(nLanguageType == 0)
		sprintf(strFileName,"%s","System\\arabic.xml");
	if(nLanguageType == 5)
		sprintf(strFileName,"%s","System\\english.xml");

	//先读取窗体的名称，根据窗体的名称获得窗体指针，然后再给窗体的各控件赋值 

	TiXmlDocument doc(strFileName);
	bool loadOkay = doc.LoadFile();
	if (!loadOkay)
	{
		return;
	}
	TiXmlNode* node = 0;
	TiXmlElement* todoElement = 0;
	TiXmlElement* itemElement = 0;
	node = doc.FirstChild( "MES" );
	assert( node );
	todoElement = node->ToElement();
	assert( todoElement  );

	node = todoElement->FirstChildElement();	 
	assert( node );
	itemElement = node->ToElement();
	assert( itemElement  );

	 
	for( node = todoElement->FirstChildElement();node;node = node->NextSibling() )
	{
		const char* str ;
		str = node->ValueTStr().c_str();		 
		
		if(strcmp(str,"MainWindow") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow),node);			 
		}
		else if(strcmp(str,"FilemanageForm") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_fileManage),node);			 
		}
		else if(strcmp(str,"FileEditChild") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_fileManage->FormFileEditChild),node);			 
		}
		else if(strcmp(str,"FileManageChild") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_fileManage->FormFileManageChild),node);			 
		}
		else if(strcmp(str,"ParamSettingForm") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_paramsetting),node);			 
		}
		else if(strcmp(str,"printSetting") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_paramsetting->m_printSetting),node);			 
		}
		else if(strcmp(str,"sysSetting") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_paramsetting->m_sysSetting),node);			 
		}
		else if(strcmp(str,"countSetting") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_paramsetting->m_countSetting),node);			 
		}
	} 
}

void CUILanguage::ChangeLanguageForItem(QObject* pWidge,TiXmlNode* node)
{
	//读入各控件信息,并赋值
	TiXmlNode* nodeTmp = 0;
	for( nodeTmp = node->IterateChildren(0);nodeTmp;nodeTmp = node->IterateChildren( nodeTmp ) )
	{
		const char* strItem = nodeTmp->ValueTStr().c_str();				 
		const char* strText; 
		TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
		strText = nodeText->ValueTStr().c_str();			 

		QPushButton *tempButton = pWidge->findChild<QPushButton *>(strItem);
		QLabel *tempLabel = pWidge->findChild<QLabel *>(strItem);
		QCheckBox *tempCheck = pWidge->findChild<QCheckBox *>(strItem);
		QTabWidget * tempQTabWidget = pWidge->findChild<QTabWidget *>(strItem); 
		QComboBox *tempQComboBox = pWidge->findChild<QComboBox *>(strItem); 
 		 
		if(tempButton)
			tempButton->setText(QString::fromLocal8Bit(strText));
		else if(tempLabel)
			tempLabel->setText(QString::fromLocal8Bit(strText));
		else if(tempCheck)
			tempCheck->setText(QString::fromLocal8Bit(strText));
		else if(tempQTabWidget)
		{
			//以#分解字符
			char seg[] = "#"; /*分隔符，分隔符可以为你指定的分号，空格等*/  
			int i =0;  
			char *substr= strtok((char*)strText, seg);/*利用现成的分割函数,substr为分割出来的子字符串*/  
    
			while (substr != NULL) {    
					tempQTabWidget->setTabText(i,QString::fromLocal8Bit(substr));
					i++;  
					substr = strtok(NULL,seg);/*在第一次调用时，strtok()必需给予参数str字符串， 
					往后的调用则将参数str设置成NULL。每次调用成功则返回被分割出片段的指针。*/  
			}    			
 		}
		else if(tempQComboBox)
		{
			//以#分解字符
			char seg[] = "#"; /*分隔符，分隔符可以为你指定的分号，空格等*/  
			int i =0;  
			char *substr= strtok((char*)strText, seg);/*利用现成的分割函数,substr为分割出来的子字符串*/  
    
			while (substr != NULL) {    
					tempQComboBox->setItemText(i,QString::fromLocal8Bit(substr));
					i++;  
					substr = strtok(NULL,seg);/*在第一次调用时，strtok()必需给予参数str字符串， 
					往后的调用则将参数str设置成NULL。每次调用成功则返回被分割出片段的指针。*/  
			}    			
 		}
	}			 
}