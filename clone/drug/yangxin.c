// Code of ShenZhou
// yangxin.c ������

inherit PILL;
#include <ansi.h>
void setup()
{}
void init();
void wear(int);

int worn;
int cure_ob(string);
void create()
{
	set_name("������", ({"yangxin wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ű��췢���������衣\n");
		set("value", 5000);
                set("no_sell", 1);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
        message_vision(HIR "$N����һ�����ĵ���ֻ����ͷ�ؽ��ᣬ�������ڣ�ԭ����ʳ���ͣ�ҩЧ�ʵ��䷴��\n" NOR, this_player());
	this_player()->add("jingli", -200);
	this_player()->apply_condition("bonze_drug", 
		this_player()->query_condition("bonze_drug")+10);
	destruct(this_object());
	return 1;
}

void init()
{
//        worn = 0;
 //       call_out("wear", 1200, 1);
	add_action("do_pour", "drop");
}



void wear(int phase)
{
        worn = phase;
        switch(phase) {
        case 1:
                set("long", "����һ�����˺ܳ�ʱ��������衣\n");
                call_out("wear", 300, phase+1);
                break;
        case 2:
                set("long", "����һ���Ѿ���̫���ε������裬�챻�绯�ˡ�\n");
                call_out("wear", 100, phase+1);
                break;
        case 3:
                destruct(this_object());
                break;
        }
}
int effect_in_liquid(object ob)
{
	if (ob->query("liquid/type") == "alcohol"){
        tell_object(this_player(), HIG"��ֻ����һ�������Ե���ð��������������˵������̩ͨ��\n"NOR);
	this_player()->add("jingli", random(10)+10*ob->query("liquid/drunk_apply"));
	if (this_player()->query("neili") > this_player()->query("max_neili")*2)
        this_player()->set("neili", this_player()->query("max_neili") *2-1);
	}
        return 0;
}
