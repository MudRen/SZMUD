// ����֮��  ay-ring.c
// by naihe 02-05-16

#include <ansi.h>
#include <armor.h>

inherit FINGER;

int query_autoload() { return 1; }

void create()
{
        set_name(BLU"����֮��"NOR, ({ "anyue ring", "ring","jie"}));
        set("weight",100);
        set("long", "һöɢ����������Ϣ��С��ָ�������ƺ�����������С�֡�\n");
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

void del_me()
{
	message_vision(""BLU"����֮��"NOR"���ط���һ�����ĵ�̾Ϣ�����ʹ���ʧ������\n",this_player());
        destruct(this_object());
}

void do_wear()
{
	if(this_player()->query("id")=="spark")
	{
		set("long", "һöɢ����������Ϣ��С��ָ�������������С�֣��κΡ�\n");
		return;
	}

	if(this_player()->query("id")=="naihe")
	{
		set("long", "һöɢ����������Ϣ��С��ָ�������������С�֣���˸��\n");
		return;
	}

	call_out("del_me",1+random(5));
}

