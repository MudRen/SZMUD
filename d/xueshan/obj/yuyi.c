// Code of ShenZhou
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void setup()
{}
void init()
{
        add_action("do_move", "get");
}
void create()
{
        set_name(HIG"������"NOR, ({"da chang", "chang"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������֯�ɵĴ�멣�������ɫ��ɷ�Ǻÿ���\n");
                set("unit", "��");
                set("material", "cloth");
		set("value", 100);
		set("armor_prop/armor", 1);
		
	}
        setup();
}
int do_move(string arg)
{
        object ob; 
        object me = this_player();
		
	if ( arg == "all") return 1;

	if (!id(arg) || file_name(environment(me)) != "/d/xueshan/dycave" )
                return 0;

	if (me->query("combat_exp") > 50000){
                message_vision(
"$N�����Ų����ë��멣�����һЩ��������Ȼ�����ϵ���ëȫ�����˿�����һƬƬ��������...��Ǻ��$Nֱ�����硣\n", this_player());

		ob = new("/d/xueshan/obj/wucan-yi");
                if (ob){
                ob->move("/d/xueshan/dycave");
                message_vision("$NͻȻ����������һ���ںڵ����¡�\n", this_player());
		}
        }
	else {
                message_vision(
"$N�����Ų�����ģ�ͻȻ����ë��멵Ŀ�����ð��һ�ɶ��������$N�ı����С�\n", this_player());
                me->unconcious();
        }
	destruct(this_object());
	return 1;
}
