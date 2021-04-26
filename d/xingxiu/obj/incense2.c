// Code of ShenZhou
// incense.c ���
// By Marz 11/11/96
// Ryu, 12/5/96

inherit ITEM;

void init();
void wear(int);

int worn;

void create()
{
	set_name("��ȼ����",({"incense"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ֦��ȼ���㣬�ճ�һ�ɵ��������㡣\n");
		set("unit", "֦");
		set("value", 10000);
    	}
	
	setup();
}

void init()
{
	worn = 0;
	call_out("wear", 120, 1); 
}



void wear(int phase)
{
	worn = phase;
	switch(phase) {
	case 1:
		set("long", "����һ֦��ȼ���㣬�Ѿ��յ�һ���ˡ�\n");
		call_out("wear", 60, phase+1); 
		break;
	case 2:
		set("long", "����һ֦��ȼ�ŵ��㣬�����������ˡ�\n");
		call_out("wear", 60, phase+1); 
		break;
	case 3:
		destruct(this_object());
		break;
	}	
}

// End of File 
