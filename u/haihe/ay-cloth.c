// ����֮�¡� ay-cloth.c
// by naihe 02-05-15

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(BLU"����֮��"NOR, ({ "anyue cloth","anyue yi","yi"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long","һ����ͨģ�����·���ȴɢ����ĳ����Ȼ����Ϣ��\n");
                set("material", "cloth");
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
