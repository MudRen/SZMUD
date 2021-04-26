// Code of ShenZhou
// yufenguan.c

#include <ansi.h>
#include <armor.h>

inherit F_AUTOLOAD;
inherit F_UNIQUE;
inherit HEAD;

void create()
{
	set_name( "���" , ({ "feng guan", "guan" }) );
    set_color("$HIC$");
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "����һ�������̳ɵķ�ڣ�����ϸ�����˵���ά��άФ�����滹����һ�ž޴��ҹ���飬�������⡣\n");
		set("value", 50000);
		set("material", "jade");
        set("regidity", 1000000);
		set("armor_prop/armor", 100);
	}

	setup();
}

int is_special() { return 1;}

int query_autoload()
{
        object me = this_player();
        if( wizardp(me) || me->query("beauty")==1 )
            return 1;
        else return 0;
}

void init()
{
        object me = this_player();

		if(me->query("gender")=="Ů��")
		{
			set("wear_msg", HIM "$N����һ�����ڣ���ʱ��â���䣬�������ǡ����������ԣ���ɷ����Ȼ�ǳ�������֮ò��������֮�ˡ�\n" NOR);
		}
		else
			set("wear_msg", HIM "$N����һ�����ڣ���ʱ��â���䣬�������ǡ�\n" NOR);

        set("unequip_msg", HIY "$N������С�������ժ��������\n" NOR);

         if (!wizardp(me)) {
                  set("no_get",   "ƥ������������㻹�����˰ɡ�\n");
                  set("no_drop",  "��ô���Ķ�����ô�������ء�\n");
                  set("no_steal", "���������͵������\n");
         }
}


mixed hit_by(object me, object victim, int damage, object weapon)
{
        string result;

        damage = damage/10;
        if( damage < 5 ) damage = 0;

        return ([ "result": result, "damage": damage+random(damage) ]);
}

