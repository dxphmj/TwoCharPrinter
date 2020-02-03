#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QWidget>

namespace Ui {
	class language;
}

class language : public QWidget
{
	Q_OBJECT

public:
	language(QWidget *parent = 0);
	~language();

private:
	Ui::language *ui;

private slots:
	void OKLanBut_clicked();
	void lanEnglish_KBBut_clicked();
	void LanChinese_KBBut_clicked();
	void LanKorean_KBBut_clicked();
	void LanJapanese_KBBut_clicked();
	void LanCzech_KBBut_clicked();
	void LanDutch_KBBut_clicked();
	void LanGerman_KBBut_clicked();
	void LanFarsi_KBBut_clicked();
	void LanHindi_KBBut_clicked();

	//void sendslot();

signals:
	void languageEvent();

};

#endif // LANGUAGE_H
