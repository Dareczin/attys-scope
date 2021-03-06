#include "current.h"

#include<qfont.h>
#include<stdio.h>


Current::Current() : QComboBox() {

	addItem(tr("I=6nA"), 0);
	addItem(tr("I=22nA"), 1);
	addItem(tr("I=6uA"), 2);

	connect(this,
		SIGNAL( activated(int) ),
		this,
		SLOT( currentChanged(int) ) );

}

void Current::currentChanged ( int index ) {
 	current = index;
	emit signalRestart();
//	_RPT1(0, "current %d\n",current);
//	fprintf(stderr,"current %d\n",current);
}

void Current::setCurrent( int c ) {
		current = c;
		setCurrentIndex(c);
}
