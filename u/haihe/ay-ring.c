// ����֮��  ay-ring.c
// by naihe 02-05-16

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name(BLU"����֮��"NOR, ({ "anyue ring", "ring","jie"}));
        set("weight",100);
	if(random(2)==1)
                set("long", "һöɢ����������Ϣ��С��ָ�������������С�֣��κΡ�\n");
	else set("long","һöɢ����������Ϣ��С��ָ�������������С�֣���˸��\n");

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("value",0);
                set("armor_prop/armor", 1);
        }
        setup();
}       

void init()
{
	add_action("do_wear","wear");
}

void do_wear()
{
	if(this_player()->query("id")!="naihe" && this_player()->query("id")!="spark")
	{
		message_vision("$N���ط���һ�����ĵ�̾Ϣ�����ʹ���ʧ������\n",this_object());
        	destruct(this_object());
	}
}
