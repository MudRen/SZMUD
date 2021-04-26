// Code of ShenZhou
// jinshe-zhuifa ����׶��
// last updated by April 2001.09.28 add skill throwing results

#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit F_EQUIP;
int throw_ob(object me, object victim);

string* xuedao = ({
        "�İ�Ѩ",
        "�ز�Ѩ",
        "��ӭѨ",
        "Ͽ��Ѩ",
        "ͷάѨ",
        "�¹�Ѩ",
        "����Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "�ػ�Ѩ",
        "�ٳ�Ѩ",
        "�ٺ�Ѩ",
        "ͨ��Ѩ",
        "����Ѩ",
        "ӡ��Ѩ",
        "����Ѩ",
        "��ҺѨ",
        "����Ѩ",
        "����Ѩ",
        "�ٻ�Ѩ",
        "��̨Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�βѨ",
        "����Ѩ"
});
string *throw_msg = ({
"$N����һö����׶����׼$nһ���֣�������׶��ֱ����$n��"+xuedao[random(sizeof(xuedao))]+"��\n",
//"$N˫�����ӣ���ö����׶���ź�Х���������ɶ�������$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))],
//"$N����Ծ�𣬾Ӹ�������$n������ö����׶��ֱȡ$n��˫Ŀ��"+xuedao[random(sizeof(xuedao))],
"ͻȻ$N��ͷ����ֻ���á�ಡ���һ����һö����׶�ɺ���ɳ�����$n��"+xuedao[random(sizeof(xuedao))]+"�����ȥ��\n",
"����$N��˫��£�����У�������Ϣ�ط���һö����׶��б�䵽$n��"+xuedao[random(sizeof(xuedao))]+"��Ѹ���ޱȣ�\n",
"$NһЦ���ˣ�����ȴ������һ�ģ�һö����׶����ǰ��Ȼ�������ȡ$n��"+xuedao[random(sizeof(xuedao))]+"��\n",
//"$N˫��ͬ�ӷ�����ö����׶����$n˫Ŀ���ſ�һ������һö����׶���������ϵس�Խǰ��ö����׶������������$n��"+xuedao[random(sizeof(xuedao))],
});
string query_throw_msg()
{
        return throw_msg[random(sizeof(throw_msg))];
}
void create()
{
        set_name("����׶", ({ "jinshe zhui", "zhui" }) );
        set_weight(1000);
        set_color(HIY);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "����׶�Ǵ������죬��Լһ������Լ����˷֣���ɰ������ࡣ\n"
                    "�����Σ������˷ֳ�˫�棬ÿһ�涼��һ�����̡���׶������\n"
                    "�и���ѩ���֡�\n");
        set("unit", "��");
        set("base_unit", "ö");
        set("value", 160000);
        set("skill", "jinshe-zhuifa");
        set("damage", 5);
                set("armor_type", "embed");
                set("armor_prop/armor",1);
                set("armor_prop/attack", -50);
                set("armor_prop/defense", -50);
                set("no_sell", 1);
                set("unequip_msg", HIR"$Nһҧ����$n���˿��ϰ���������һ����Ѫ�͵�ӿ�˳�����\n"NOR);
        }
        set_amount(16);
        setup();
}
int throw_ob(object me, object victim)
{
        string str, dodge_skill, action, limbs;
        int ap, dp;
        object ob2, ob = this_object();
        
        action = query_throw_msg();
        message_vision(HIY+action+NOR, me, victim);

        ap = me->query_skill("jinshe-zhuifa", 1);
		ap += me->query_skill("throwing",1);
		ap /= 10;
		ap += me->query_str();
		ap += me->query("jiali")/10;
        dp = victim->query_skill("throwing",1)/10;
		dp += victim->query_dex();

        ap *= me->query("combat_exp")/1000;
        dp *= victim->query("combat_exp")/1000;

        ap = random(ap*2);

        if ( ap > dp){
        limbs = victim->query("limbs");

                if(!victim->query_temp("armor/embed")){
                message_vision(CYN"\n���$Nһ���ҽУ�$n��Ȼ����$N��"+limbs[random(sizeof(limbs))]
                          +"�ϡ�\n"NOR, victim, ob);
                                 ob2=new(__FILE__);
                                 ob2->set_amount(1);
                                 ob2->set("embedded", 1);
                                 ob2->move(victim);
                                 ob2->do_embed();
                                 victim->receive_wound("qi", (me->query_str()+me->query("jiali"))
									*ob->query("damage"), me);
                                 victim->receive_damage("qi", ob->query_weight()/100, me);
                        victim->kill_ob(me);
                }
                else {
                message_vision(CYN"�����$N��"+limbs[random(sizeof(limbs))]
                          +"���һ�����ˡ�\n"NOR, victim);
                                victim->receive_wound("qi", me->query_str());
                                ob2=new(__FILE__);
                                ob2->set_amount(1);
                                ob2->move(environment(me));
                                victim->fight_ob(me);
                }
                me->start_busy(random(3));
                ob->add_amount(-1);
        }

        else if ( ap < dp/7 && victim->query("race") == "����"){
                message_vision(CYN"����$N�����ֿ죬����һ�࣬��$n����ؽ������\n"NOR, victim, ob);
                me->start_busy(random(3));
                                 ob->add_amount(-1);
                                 ob2=new(__FILE__);
                                 ob2->set_amount(1);
                                 ob2->move(victim);
        }
        else {
        dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                str = SKILL_D(dodge_skill)->query_dodge_msg();
                message_vision(str, me, victim);
                victim->fight_ob(me);
                me->start_busy(random(3));
                add_amount(-1);
                                 ob2=new(__FILE__);
                                 ob2->set_amount(1);
                                 ob2->move(environment(me));
        }
        return 1;
}
int wear() { return 0; }
int do_embed()
{
        ::wear();

        set("no_drop", 1);
        set("no_get", 1);

        environment()->apply_condition("embedded", 100);

        return 1;
}
int unequip()
{
        ::unequip();

                set("no_drop", 0);
                set("no_get", 0);
                set("embedded", 0);

        environment()->apply_condition("embedded", 0);
        environment()->receive_damage("qi", 200+random(1000));

        return 1;
}
string query_autoload()
{
        if( query("equipped") )
        return query_amount() + "";
}

void autoload(string param)
{
        int amt;

        if( sscanf(param, "%d", amt)==1 )
                set_amount(amt);
        set("embedded", 1);
        set("no_drop", 1);
        set("no_get", 1);
        ::wear();
}
