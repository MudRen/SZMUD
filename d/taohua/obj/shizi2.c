// Room Of Mxj
// have a good day
//Cracked by Kafei
//kane
//maco changed 
#include <ansi.h>
#include <combat.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit F_COMMAND;


int bash_weapon(object me, object victim);

void create()
{
	set_name(YEL"Сʯ��"NOR, ({"xiao shizi", "shizi"}));
	if (clonep())
	set_default_object(__FILE__);
	else {
	set("unit", "��");
	set("base_unit","��");
	set("long", "�����洦�ɼ���Сʯ�ӡ�\n");
	set("value", 0);
	}
	set_amount(20+random(20));
//	init_throwing(5);
	setup();
}

int init()
{
	add_action("do_tanzhi", "tan");      
	add_action("do_liantan", "liantan");   
}

int do_liantan(string arg)
{
	string* xuedao = ({
	"�޹�Ѩ",
	"�ز�Ѩ",
	"�羮Ѩ",
	"�ճ�Ѩ",
	"����Ѩ",
	"���Ѩ",
	"����Ѩ",
	"�縮Ѩ",
	"����Ѩ",
	"�յ�Ѩ",
	"ǿ��Ѩ",
	"�ٺ�Ѩ",
	"����Ѩ",
	"����Ѩ",
	"����Ѩ",
	"��׵Ѩ",
	"��βѨ",
	"����Ѩ",
	"�͹�Ѩ",
	"�ٻ�Ѩ",
	"��̨Ѩ",
	"̫��Ѩ",
	"����Ѩ",
	"����Ѩ",
	"�βѨ",
	"������",
	"����Ѩ"
	});

	int skill,skill2,tz,tz_busy,exp1,exp2,exp0,jiali;
	object me = this_player();
	object victim,weapon,ob;
	mapping myfam;
	
	if (!arg)    
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(victim = present(arg,environment(me))))
		return notify_fail("���ﲢ�޴��ˣ�\n");	
		
	if (!victim)
		return notify_fail("���ﲢ�޴��ˣ�\n");

	if (!living(victim))
		return notify_fail("�ⲻ�ǻ��\n");	
		
	if (victim == me) return notify_fail("�αض��һ�٣�\n");	
	
	if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");
        
       	myfam = (mapping)me->query("family");	
	if( !myfam || myfam["family_name"] != "�һ���" )
                return notify_fail("����һ����ӣ�����ʹ�þ�ָ�����ľ�����\n");                

	if( me->query_skill_mapped("force") != "bitao-xuangong" )
		return notify_fail("�����õĲ��Ǳ����������޷�ʹ�þ�ָ�����ľ�����\n");
	
	if( me->query_temp("liantan",1) )
		return notify_fail("������ʹ�þ�ָ������\n");
		
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");		
	
	if (me->query_skill("tanzhi-shentong", 1) < 240)
		return notify_fail("��ĵ�ָ��ͨ����������\n");		
		
	if (me->query_skill("bitao-xuangong", 1) < 240)
		return notify_fail("��ı�����������������\n");	
	
			
	if ((int)me->query("jingli") < 500)
		return notify_fail("��ľ���������\n");
	if ((int)me->query("neili") < 1000)
		return notify_fail("�������������\n");		

	ob = this_object();
	if (ob->query_amount() < 5)
		return notify_fail("���Сʯ������������\n");		
	
	if( !victim
        ||  !victim->is_character()
        ||  !me->is_fighting(victim) )
                return notify_fail("��ָ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
					
	skill = me->query_skill("tanzhi-shentong", 1);
	skill2 = victim->query_skill("dodge",1);	
	exp1 = me->query("combat_exp");
	exp2 = victim->query("combat_exp");
	
	jiali = me->query("jiali");
	
	tz = (65+100*(skill-skill2)/skill)*(2*exp1)/(exp1+exp2);
	tz_busy = 2+(skill-240)/20;				
			
	message_vision(HIW"$N��Хһ����������ָ�������죬��ָ������ֻ�������͵������ƿ�֮�����ϣ�\n
ֻ��$N�������м���������ʯ�ӣ�����������֮�Ʒ�Ϯ$n���С����š��ٻᡢ̫����������Ѩ��\n"NOR, me, victim);
	me->add("neili",- 400);
	
// �ɹ�
	if (tz>random(100)) {
	message_vision(HIY"$nֻ����"+xuedao[random(sizeof(xuedao))]+"һ�����飬��Ѫ��ӿ����ʱ�������ã�\n"NOR, me, victim);
	victim->start_busy(tz_busy);
	victim->receive_wound("qi", jiali);
	victim->receive_damage("qi", jiali);
	add_amount(-5);   
	me->set_temp("liantan",1);
//	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :),tz_busy*2+4 );
//	call_out("checking", 1, me); 
	call_out("remove_effect",tz_busy*2+4,me );
	return 1;
	}
	else {
	message_vision(CYN"$n�����Ʋ��չ���Ṧ����������\n"NOR, me, victim);	
	me->start_busy(2);
	return 1;
	}	
}
void checking(object me)
{
	if( !me->is_fighting() ) {
	message_vision(CYN "\n$N��ս���ѱϣ��㼴�����˾�ָ�����Ĺ��ơ�\n"NOR,me);
	me->delete_temp("liantan");
	return ;
	}
}	

int remove_effect(object me)
{
	
	message_vision(CYN"$Nֻ��ָ������������˿칥���º�̷��������²�����ɫ���������˾�ָ�����Ĺ��ơ�\n"NOR,me);
	me->delete_temp("liantan");
	return 0;
}	

int do_tanzhi(string arg)
{
	int skill, skill2, thr, dod, tz, parr, diff, jiali, exp, exp2;
	string str, dodge_skill, result, *limbs, limb;
	object me = this_player();
	object victim,weapon;

	if (!arg)    
		return notify_fail("��Ҫ��ʲô��\n");

	if (!(victim = present(arg,environment(me))))
		return notify_fail("���ﲢ�޴��ˣ�\n");

	if (!victim)
		return notify_fail("���ﲢ�޴��ˣ�\n");

	if (!living(victim))
		return notify_fail("�ⲻ�ǻ��\n");

	if( me->is_busy() )
		return notify_fail("��ǰһ��������û�����ꡣ\n");

	if (victim == me) return notify_fail("�αض��һ�٣�\n");

//	if (!wizardp(me) && wizardp(victim))
//		return notify_fail("�󵨣�����ı����ʦ��\n");
        
	if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

	if (me->query_skill("tanzhi-shentong", 1) < 120)
		return notify_fail("ѧС����ʯ�ӣ���������\n");

	tz = me->query_skill("tanzhi-shentong", 1);
	dod = (int)victim->query_skill("dodge");
	parr = (int)victim->query_skill("parry");
	skill = tz/10+random(tz)/2;
	skill2 = (dod + parr)/10;
	diff = skill-skill2;
	jiali = me->query("jiali");
	limbs = victim->query("limbs");
	exp = me->query("combat_exp");
	exp2 = victim->query("combat_exp");
	me->add("neili",- jiali/2);
	limb = limbs[random(sizeof(limbs))];

	message_vision(HIW"$N��������һ��Сʯ�ӣ�����Ĵָʳָ֮�䣬���ꡱ��һ�����죬Сʯ����$n�����ȥ......\n" NOR, me, victim);

//	if( exp/3+random(exp/2) > exp2 /2 && skill > skill2){
	if(skill > skill2){

	weapon = victim->query_temp("weapon");

	if( !victim->query_temp("weapon") ) {

		if(jiali >= 240) message_vision(HIY"$n������һ����Ϣ��Сʯ��ת˲�仮�����գ��ѻ���$n"+limb+"���������ˣ������ɵ���\n" NOR, me, victim);

		else if(jiali >= 200) message_vision(HIY"����Сʯ���ƿ�֮�������쳣�����Ʊ���̥����������Ҫ������ת˲���ѻ���$n"+limb+"��\n" NOR, me, victim);
		else message_vision(HIY"$n��������ֲ��������ڵ�ʱ��Ѫ�������ֱ���Ҳ̧��������\n" NOR, me, victim);

	victim->receive_wound("qi", random(jiali) +random(10));
	victim->receive_damage("qi", jiali + random(jiali) + random(10));
	}
	else message_vision(HIY"Сʯ���ƿշ�����ײ��$N���е�" + weapon->name() + HIY"�ϡ�\n"NOR,victim);
   
	bash_weapon(me,victim);
	victim->start_busy(1+random(2));

	victim->receive_wound("qi", random(jiali/5) + 10);
	victim->receive_damage("qi", jiali/2 + random(10));
	result = COMBAT_D->eff_status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
	message_vision("( $N"+result+" )\n", victim);
		if(victim->query("eff_qi") < 0 && victim->query("qi") < 0 && jiali >200 
		&& victim->query("race") == "����")
		message_vision(HIR"\n$n����һ���������ˤ�����һ����Ѫ��\n" NOR, me, victim);



	if( !victim->is_killing(me) ) victim->kill_ob(me);
	me->start_busy(1+random(2));
	if( victim->query("combat_exp") > me->query("combat_exp"))
	me->add("combat_exp", 1);
	add_amount(-1);      

	return 1;
	}
	
	else {
        dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                str = SKILL_D(dodge_skill)->query_dodge_msg(limb);
                message_vision(str, me, victim);

//	message_vision("$n���ֲ���Ͻ�����Ծ�����ɣ����˿�ȥ��\n" NOR, me, victim);
		if( !victim->is_killing(me) ) victim->kill_ob(me);
	me->start_busy(random(2));
		if (query_amount() >1) add_amount(-1);
                else destruct(this_object());
	}
	return 1;
}    

int bash_weapon(object me, object victim)
{
        object ob;
        int wap, wdp, jiali;
	jiali = me->query("jiali");

        if( (me->query("neili") > 100)
        &&      ob = victim->query_temp("weapon") ) {
                wap = (int)me->query("neili")
                        + (int)me->query_str()
                        + (int)me->query_skill("tanzhi-shentong",1);
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str()
                        + (int)victim->query_skill("parry")/2;
                wap = random(wap);
                if( wap > 2 * wdp 
                && ob->query("weapon_prop/damage") < 90 ) {
			if(jiali < 200) message_vision(HIW "ֻ������ž����һ����$N���е�" + ob->name() + HIW"�Ѿ���Ϊ���أ�\n" NOR, victim );
			else message_vision(HIW"Сʯ��һײ֮�£���ʱ�����Ľ���ʯ����Ƭ�˷����䣬��ž����һ����"+ob->name()+HIW"��Ϊ���أ�\n"NOR, victim);
			
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "�ϵ���" + ob->query("name"));
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
                } else if( wap > wdp ) {
                
                        if(jiali < 200) message_vision(HIW"$Nֻ��������" + ob->name() + HIW"�ѳֲ��������ַɳ���\n"NOR, victim);
			else message_vision(HIW"Сʯ��һײ֮�£�ը�÷��飬���$N������ʹ��"+ ob->name() + HIW"ˤ�ڵ��£�\n"NOR, victim);
	
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp / 2 ) {
			message_vision("$Nֻ��������" + ob->name() + "һ����Щ���֣�\n",
                                victim);
                } else {
                        message_vision("$N�����Сʯ�Ӻ�$n��"+ob->name()+"�����ð�����Ļ��ǡ�\n", me, victim);
                }
        }
}


