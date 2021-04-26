// Code of ShenZhou
// Ryu, 12/5/96

inherit ITEM;
#include <ansi.h>;

void init();
void wear(int);

int worn;

void create()
{
	set_name(HIR"һ�ѻ���"NOR,({"huo yan"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIR"�����Լ�ߣ�"+GRN+"ɫ�����̣�"+BLU+"����ɭɭ��"+HIR+"��Ѱ��������졣\n"NOR);
		set("unit", "��");
		set("value", 10000);
		set("no_get", 1);
		set("no_drop", 1);
    	}
	
	setup();
}

void init()
{
	worn = 0;
	call_out("wear", 100, 1); 
}



void wear(int phase)
{
	worn = phase;
	switch(phase) {
	case 1:
		set("long", HIR"��������ȼ���ţ�"+GRN+"ɫ�����̣�"+BLU+"����ɭɭ��"+HIR+"��Ѱ��������졣\n"NOR);
		call_out("wear", 100, phase+1); 
		break;
	case 2:
		set("long", RED"����Խ��Խ���������������ˡ�\n"NOR);
		call_out("wear", 30, phase+1); 
		break;
	case 3:
		message_vision(RED"���潥����Ϩ���ˡ�\n"NOR, this_object());
		destruct(this_object());
		break;
	}	
}

// End of File 
