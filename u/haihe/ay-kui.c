// ����֮��  ay-kui.c
// by naihe 02-05-16

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(BLU"����֮��"NOR, ({ "anyue kui", "kui" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ͨģ����ͷ����ȴɢ����ĳ����Ȼ����Ϣ��\n");
                set("value", 0);
                set("material", "steel");
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
