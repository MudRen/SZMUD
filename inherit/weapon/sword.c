// Code of ShenZhou
// sword.c
#include <ansi.h>
#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_sword(int damage, int flag)
{
        if( clonep(this_object()) ) return;

        set("weapon_prop/damage", damage);
        set("flag", (int)flag | EDGED);
        set("skill_type", "sword");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
        }
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object ob;
	object weapon = me->query_temp("weapon");
	int j, k; 
	
        if (victim->query_temp("armor/cloth") 
	&& random(weapon->query("weapon_prop/damage")) >= 10){
	ob = victim->query_temp("armor/cloth");
	if (!ob->query("wreckage"))
	ob->set("origina_armor", ob->query("armor_prop/armor"));
	
	if (ob->query("armor_prop/armor") > 0 && ob->query("armor_prop/armor") < 150){
        ob->add("armor_prop/armor", -1);
	ob->add("wreckage", 1);
	victim->add_temp("apply/armor", -1);

	k=ob->query("original_armor");
	j=ob->query("armor_prop/armor");

	if ( j < k/4 || j < 1){
        ob->set("long", "һ�����Ʋ�����"+ob->query("name")+"\n");
        if (!ob->query("wreck")){
        ob->set("name", "��" + ob->query("name"));
        ob->set("value", 0);
        ob->add("wreck", 1);
                }
        }
        if ( j < k/2 && j > k/4){
        ob->set("long", "һ���������˼�������"+ob->query("name")+"\n");
        ob->set("value", ob->query("value")/3);
        }
        if ( j < k && j > k/2){
        ob->set("long", "һ�����˼����ڵ�"+ob->query("name")+"\n");
	ob->set("value", ob->query("value")/2);
	     }
	if (ob->query("material") != "steel" && ob->query("material") != "iron")
        return HIW"ֻ�������͡���һ����$n���ϵ�"+ob->query("name")+HIW+"������һ�����ӡ�\n"NOR;
        else
        return HIW"ֻ������������һ����$n���ϵ�"+ob->query("name")+HIW+"������һ��ȱ�ڡ�\n"NOR;
	}
	
    }
}
