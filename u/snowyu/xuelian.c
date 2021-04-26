// Code of ShenZhou
// medicine: xuelian.c
// Jay 3/18/96
// Ryu, 12/5/96
#include <ansi.h>;
inherit ITEM;
inherit F_AUTOLOAD;

 int query_autoload() { return 1; }
void setup()
{}

int cure_ob(string);
void create()
{
        set_name(HIM"ѩ��"NOR, ({"xuelian", "lian", "lotus"}));
	set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ڴ��һ��ѩ��������������������̱�ѩ�㾧Ө��ף���������м䳤��ϸ˿״���Ϻ�\n"
			    "ɫ�ͳ�ɫ���\n");
                set("value", 20000);
                set("no_sell", 1);
		set("medicine", 1);
        }
        setup();
}

int cure_ob(object me)
{
	if (me->query_condition("cool_drug") > 0){
        me->add("max_jingli", -1);
	me->add("eff_jingli", -1);
        message_vision(HIR "$N����һöѩ����ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        destruct(this_object());
        return 1;
        }
   message_vision(HIM"$N����һ֧ѩ����һ������Ƶ����������ķΣ��پ�������ˬ��\n"NOR, me);
	me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        me->set("jingli", (int)me->query("max_jingli"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
	me->apply_condition("cool_drug", 30);

        if (random(2)==1){ 
	me->add("max_jingli", 1);
	me->add("eff_jingli", 1);
	}

        me->set("neili", (int)me->query("max_neili"));

        if ((int)me->query_condition("snake_poison") > 0) 
        me->apply_condition("snake_poison", 0);
  
        if ((int)me->query_condition("insect_poison") > 0) 
        me->apply_condition("insect_poison", 0);
 
        if ((int)me->query_condition("sl_poison") > 0) 
	me->apply_condition("sl_poison", 0);
   
        if ((int)me->query_condition("xx_poison") > 10 
        && (int)me->query_condition("xx_poison") < 50) 
        me->apply_condition("xx_poison", 0);
  
   destruct(this_object());
   return 1;
}

void init()
{
    add_action( "dai", "dai" );
    add_action( "remove", "remove" );
}

int dai( string arg )
{
    object me = this_player();
    object xl = this_object();
    if ( arg && arg == "xue lian" )
    {
        message_vision( HIG"$N��һ��$n"+HIG"����ͷ�ϡ�\n"NOR, me, xl );
        xl->set( "equipped", 1 );
        return 1;
    }
}

int remove( string arg )
{
    object me = this_player();
    object xl = this_object();
    if ( arg && arg == "xue lian" )
    {
        message_vision( HIG"$N��һ��$n"+HIG"��ͷ������������\n"NOR, me, xl );
        xl->delete( "equipped" );
        return 1;
    }
}

