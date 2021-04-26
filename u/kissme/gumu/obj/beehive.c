// beehive.c ����
// by April	01.08.26
// update by April 01.10.30

// temp means
// owner ��������
// mi_lvl �Ѳɵ÷���������ÿ�������20
// down �����Ƿ���ڵ���
// open �������Ƿ���
// escaped ���������
// last_place �ϴβ��۵ص�
// mi_left ���ؿɲɷ�������
// bee_count ���Ⱥ��Ŀ
// bee_org ����Ѿ���������
// bees ���������������Ⱥ
// bee_training ������ڽ���ѵ��

#define MAX_MI 20			//һ�������������
#define TICK 10			//auto_check�������ʱ��
#define R_TICK 10		//auto_check����������ʱ��
#define T_COST 10		//ÿtick���ľ���
#define C_COST 20		//callback���ľ���
#define T_EXP 4			//ÿtick����exp
#define R_EXP 4			//ÿtick�������exp
#define T_POT 2			//ÿtick����pot
#define R_POT 2			//ÿtick�������pot
#define T_BEE 10		//ÿtick����bee-traing skill
#define R_BEE 10		//ÿtick�������bee-traing skill
#define RDM	20			//ѵ��ʱ��������ĸ���

#include "ansi.h"

//inherit ITEM;
inherit COMBINED_ITEM;

void setup_skill(object me,object obj);
void do_leave(object ob);
void destroy_me(object me);

string *phases = ({
	"��������ȥ��ͣ���ڻ�����æµ�š� \n",
	"����������дʣ���������䲻�����Ƿ�Զ�� \n",
	"�㾯��ؼ����Ų�Զ��������������ȸ��\n",
});

void create()
{
	set_name(HIW "�����" NOR, ({ "feng xiang", "beehive", "box", "xiang" }) );
//	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",	HIW"���ǹ�Ĺ��ľ�Ƶ�����䡣�������˵ģ���֪���ж�����䡣\n"NOR );
		set("base_unit", "��");
        set("value", 1000);
        set("material", "wood");
		set("no_sell", 1);
		set("no_give",0);
		set("no_get",1);
		set("base_weight",5000);
	}

	set("no_refresh", 1);

	set_amount(1);
	setup();
}

void init()
{
	object me = this_player();
	if ( me->query("id",1)!="sun popo" ) {
		set("no_drop",  "��ô���õĶ�����ô�������ء�\n");
		set("no_steal", "���������͵������\n");
	}

	add_action("do_open", "open");
	add_action("do_close", "close");
	add_action("do_check", "check");
	add_action("do_putdown", "putdown");
	add_action("do_putdown", "fang");
	add_action("do_carry", "tai");
	add_action("do_carry", "carry");
	add_action("do_give", "give");
	add_action("do_qufeng", "qufeng");
	add_action("do_direct", "direct");
	add_action("do_add", "add");
	add_action("do_cai", "cai");

}

int do_open(string arg){
	object me = this_player();
	object ob = this_object();
	string descrp;

	if(!arg || (arg != "feng xiang" && arg != "beehive" && arg != "box" && arg != "xiang"))	
		return 0;
	if (ob->query("open")) return notify_fail("���Ϳ�ˣ� \n");
	if( ob->query("owner") != me ) return notify_fail("����ķ�����\n");
	if(me->is_busy()) return notify_fail("����æ���أ� \n");
	if (!ob->query("down"))	return notify_fail("����Ȱ��������£� \n");
	if (ob->query("open")) return notify_fail("������ſ����أ� \n");
	if(query("bee_out")) return notify_fail("������Ⱥæ���أ�\n");

	if (ob->query("mi_lvl") >= MAX_MI*query_amount()){
		message_vision(HIG"$N����ش��������ţ�����һ�����Ҳû������\n"NOR,me);
		return notify_fail("��������Ѿ��ɵ��㹻�ķ����ˡ���ֻ���ֹ����������š�\n");
	}

	if (ob->query("escaped")){
		message_vision(HIG"$N����ش��������š��м�ֻ���̽��̽ͷ�������˻�ȥ��\n"NOR,me);
		return notify_fail("����������˾��ţ������εع������������š�\n");
	}

	remove_call_out("auto_check");
	call_out("auto_check", TICK+random(R_TICK) );

	message_vision(HIG"$N����ش��������ţ����½½�����طɳ���������ȥ�ˡ�\n"NOR,me);

	ob->set("open",1);
	ob->set("lastplace",environment(me));
	
	return 1;
}

int do_close(string arg){
	object me = this_player();
	object ob = this_object();
	string descrp;

	if(!arg || (arg != "feng xiang" && arg != "beehive" && arg != "box" && arg != "xiang"))	
		return 0;
	if (!ob->query("open")) return notify_fail("���Ϳ�ˣ� \n");
	if( ob->query("owner") != me ) return notify_fail("������ķ�����\n");
	if(me->is_busy()) return notify_fail("����æ���أ� \n");
	if (!ob->query("down"))	return notify_fail("����Ȱ��������£� \n");
	if (!ob->query("open"))	return notify_fail("������Ź����أ� \n");
	if (me->query("jingli")<C_COST+10) return notify_fail("���Ѿ���ƣ���ߣ��޷��ٻ��������ˣ� \n");

	message_vision(HIG"$N���������дʣ�һ������½½�����ض����˻�����$N�������������š�\n"NOR,me);

	ob->set("open",0);
	ob->set("bee_training",0);
	me->receive_damage("jingli", C_COST, "��������ˣ�");

	remove_call_out("auto_check");

	return 1;
}

int do_check()
{
	object me = this_player();
	object ob = this_object();
	int max = MAX_MI*query_amount();
	string descrp;

	if (ob->query("owner"))
		descrp = WHT"�������װ������"+ob->query("owner")->query("name")+"����ѱ�������Ⱥ��\n"NOR;
	else {
		descrp = WHT"һ�������ķ��䡣�Ѿ���Ұ��ռ���ˡ�\n"NOR;
		descrp += WHT"��˳�־Ͱ�������ˡ�\n"NOR;
		write(descrp);
		destroy_me(ob);
		return 1;
	}

	if (ob->query("mi_lvl") == 0)
		descrp += WHT"���������������һƬ������Ե÷��겻���������þ�������ǳ�ȥ���ۡ�\n"NOR;
	else if (ob->query("mi_lvl") <= max*3/10)
		descrp += WHT"�������������Ȼ��ǿ�������������۲��Ǻܶࡣ\n"NOR;
	else if (ob->query("mi_lvl") <= max*6/10)
		descrp += WHT"�����������ʱ��ʱ����������������һЩ�����ˡ�\n"NOR;
	else if (ob->query("mi_lvl") <= max*9/10)
		descrp += WHT"����������������������������������Ѿ�����������ˡ�\n"NOR;
	else if (ob->query("mi_lvl") == max)
		descrp += WHT"����ȫ��ɳɳ����������������������������Ѿ��������ˡ� \n"NOR;

	write(descrp);

	if (ob->query("open")) {
		if (ob->query("mi_left") == 0) write(WHT"�������䲻ͣ�������ܴ�ת����������ûʲô��ֵ�ˡ�\n"NOR);
		else if (ob->query("mi_left") == 1)	write(WHT"Խ��Խ�����������ܴ�ת���������ﻨ�ۿ�����ˡ�\n"NOR);
		else write(WHT"��������ڵĲɻ��ۡ�\n"NOR);
	}
	else write(WHT"�������Ź��š�\n"NOR);

	return 1;
}

int do_putdown(string arg)
{
	object me, ob;
	me = this_player();
	ob = this_object();

	if(!arg || (arg != "feng xiang" && arg != "beehive" && arg != "box" && arg != "xiang"))	
		return 0;
	if (ob->query("down")) return notify_fail("���Ϳ�ˣ� \n");
	if( !ob) return notify_fail("�㲢û�����ŷ��䰡��\n");
	if(environment(me)->query("short") != "����") return notify_fail("���Ҳ������ʵĵط��ŷ��䣡 \n");
	if( ob->query("owner") != me ) return notify_fail("����ķ�����\n");
	if(present("feng xiang", environment(me))) return notify_fail("�����Ѿ��б����ڷ�������ˡ�\n");
	if( ob->query("lastplace") == environment(me)) return notify_fail("����������ɹ��ۣ�\n");

	ob = present("feng xiang", me);

	if(me->is_busy())
		return notify_fail("����æ����! \n");

	message_vision(HIB"$N������������һ����յأ�����ذѷ�����ڵ��ϡ�\n"NOR,me);

	ob->set("down",1);
	ob->move(environment(me));
	ob->set("mi_left",5+random(5));

	return 1;
}

int do_carry(string arg)
{
	object me, ob;
	me = this_player();

	if(!arg || (arg != "feng xiang" && arg != "beehive" && arg != "box" && arg != "xiang"))	
		return notify_fail("��Ҫ��ʲô�� \n");

	ob = present("feng xiang", environment(me));
	if(!ob)	return notify_fail("�����з��䰡��\n");
	if (!ob->query("down")) return notify_fail("���Ϳ�ˣ� \n");
	if (me->is_busy()) return notify_fail("����æ���أ�\n");
	if( ob->query("owner") != me ) return notify_fail("����ķ�����\n");
	if( ob->query("open") || ob->query("bee_out"))
		return notify_fail("�㻹���Ȱ�����л����ɣ�\n");
	
	message_vision(HIR"$NС��������̧����䣬���¾������������䡣\n"NOR,me);

	ob->set("down",0);
	ob->move(me);

	return 1;
}

int auto_check()
{
	object me = this_player();
	object ob = this_object();
	object maque;
	int bee_lvl = (int)me->query_skill("bee-training",1);

	int i,r;
	int g_exp,g_pot,g_bee,g_mi;
	
	r = query_amount();
	g_exp = to_int((T_EXP+random(R_EXP + bee_lvl/30))*pow(r,0.5))*6/5;
	g_pot = to_int((T_POT+random(R_POT + bee_lvl/50))*pow(r,0.5))*6/5;
	g_bee = (T_BEE+random(R_BEE))*r*6/5;
	g_mi = to_int(pow(r,0.5));
	
	if ( query("bee_training") ) {
		g_exp += to_int((T_EXP+random(R_EXP + bee_lvl/20))*pow(r,0.5));
		g_pot += to_int((T_POT+random(R_POT + bee_lvl/40))*pow(r,0.5));
		g_bee += (T_BEE+random(R_BEE))*r;
	}

	if (me->query("jingli")<T_COST+10){
		ob->set("escaped",1);
		message_vision(HIR"$N�Ѿ���ƣ���ߣ������������$N�Ŀ��ƣ�\n"NOR,me);
		return 0;
	}

	if(maque = present("ma que", environment(ob))) {
		if (living(maque)){
			ob->set("escaped",1);
			message_vision(HIR"��ȸѸ�ٵ���һֻ��䣬һת�۱�����ˣ��ŵ���䶼��ط�����ȥ�ˡ�\n"NOR,me);
			destruct(maque);
		return 0;
		}
	}

	if( environment(ob) != environment(me) ){
		ob->set("escaped",1);
		message_vision(HIR"����ʱ����ô���ˣ���䶼û�˹�������\n"NOR,me);
		return 0;
	}

	write(phases[random(3)]);
	if (query("mi_left") == 0) write(WHT"�������䲻ͣ�������ܴ�ת����������ûʲô��ֵ�ˡ�\n"NOR);
	else if (query("mi_left") == 1)	write(WHT"Խ��Խ�����������ܴ�ת���������ﻨ�ۿ�����ˡ�\n"NOR);

	me->receive_damage("jingli", random(T_COST), "��������ˣ�");
	ob->set("bee_training",0);

	if (g_exp > 25) g_exp = 20;
	if (g_pot > 10) g_pot = 8;

	if (ob->query("mi_left") && ob->query("mi_lvl")<MAX_MI*query_amount() ) {
		me->add("gm/exp",g_exp);
		me->add("gm/pot",g_pot);
		me->add("gm/lvl",g_bee);
		me->add("combat_exp",g_exp);
		me->add("potential",g_pot);
		if(me->query("potential")>me->query("max_potential"))
			me->set("potential",me->query("max_potential"));
		me->improve_skill("bee-training", g_bee, 0);
		ob->set("mi_lvl",ob->query("mi_lvl")+g_mi);
		if( g_mi == 1) ob->set("mi_left",ob->query("mi_left")-1);
		else if (query("mi_left")>1) ob->set("mi_left",ob->query("mi_left")-2);
		else set("mi_left",0);
	}

	r = random(RDM);
	if (r == 1 && bee_lvl<30 ){
		message_vision(HIR"һֻ���ͻȻ�ܾ����ݺݵ���$N���϶���һ�ڡ�\n"NOR,me);
		me->apply_condition("yufeng_poison", random((30-bee_lvl)/2) 
			+ me->query_condition("yufeng_poison"));
	}
	else if (r==2) {
		message_vision("$N����һЩ�����һ���ط���ֵ����ţ�Ҳ����ʲôҩ�Ŀ��Բ�(cai yao)�ɡ�\n",me);
		environment(me)->set("yaocai",1);
	}
	else if (r >= RDM - query_amount()) {
		maque = new("/kungfu/class/gumu/npc/maque2");
		maque->move(environment(ob));
		message_vision(HIR"ͻȻһֻ��ȸ�������˹�ȥ��$N��æ��ֹ��\n"NOR,me);
		maque->set("combat_exp",me->query("combat_exp"));
		if (me->query("combat_exp")>20000) maque->set("combat_exp",20000);
		maque->kill_ob(me);
	}
	else me->start_busy(1+random(3));

	call_out("auto_check", TICK+random(R_TICK) );
	return 1;
}

int do_give(string arg)
{
	string target, item;
    object obj, who, me=this_player();

    if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

    if( sscanf(arg, "%s to %s", item, target)==2
        || sscanf(arg, "%s %s", target, item)==2 );
    else return notify_fail("��Ҫ��˭ʲô������\n");

	if ( item != "beehive" && item !="box" && item != "xiang" ) return 0;
	if ( target != "sun" && target !="nanny" ) return 0;
	if ( !objectp(obj = present(item, me)) ) return notify_fail("������û������������\n");
	if (me->is_busy()) return notify_fail("����æ���ء�\n");
    if (!objectp(who = present(target, environment(me))) || !living(who))
        return notify_fail("����û������ˡ�\n");
	if ( userp(who) ) return notify_fail("�Է�����������������\n");
	if ( who->query("race") != "����" )
		return notify_fail("���Ҳ������ô������佻��������\n");
	if( who == me) return notify_fail("�Լ����Լ�����\n");

	message_vision("$N��$n"+chinese_number(query_amount())
		+"��"+HIW"����䡣\n"NOR, me, who);

	if ( obj->query("owner") == me ) {
		if(query("escaped")) {
			message_vision(CYN"$N������˼��ɦ��ɦͷ��\n"NOR, me, who);
			message_vision(CYN"$N��������������˵������ι���û�ɺá�\n"NOR, me, who);
			message_vision(CYN"$n����������$N��ͷ��\n"NOR, me, who);
			message_vision(CYN"$n�Ͱ��ض�$N˵����û��ϵ���´�ע��ͺá�\n"NOR, me, who);
			me->add_temp("bee_count", -1 );
			me->add("bee_count", -1 );
			if(me->query_temp("gm_xunfeng",1) ) me->delete_temp("gm_xunfeng");
		}
		else{
			message_vision(CYN"$n����������$N��ͷ��\n"NOR, me, who);
			message_vision(CYN"$n�Ͱ��ض�$N˵��������$N������ȥ��Ϣһ�°ɡ�\n"NOR, me, who);
			if(me->query_temp("gm_xunfeng",1) ) me->delete_temp("gm_xunfeng");
		}
		if ( me->query("gm/job") == 1 ){
			if ((me->query("gm/exp")+me->query("gm/pot")+me->query("gm/lvl")) != 0)
				log_file("/job/gm-bee",sprintf("[%s] %s(%s) �� %d ��ķŷ乤����ȡ�� %d �㾭�� �� %d ��Ǳ�� �� %d ��������\n", ctime(time()),me->name(), me->query("id"),time()-me->query("gm/time"),me->query("gm/exp"),me->query("gm/pot"),me->query("gm/lvl")));
			me->delete("gm",0);
		}
	}
	else {
		message_vision(CYN"$n��$N΢΢Ц��Ц��\n"NOR, me, who);
		message_vision(CYN"$n˵������л����\n"NOR, me, who);
	}

	destruct(obj);
	
	return 1;
}

int do_qufeng(string arg)
{
	object bees;
	object me = this_player();
	int lvl = me->query_skill("bee-training",1);
	int bee_exp;
	int bee_life;

	if(!arg || (arg != "out" && arg != "back" ) )return 0;
	if(me->is_busy()) return notify_fail("����æ���أ�\n");

	if (arg=="out"){
		if( query("owner") != me ) return notify_fail("����ķ�����\n");
		if (!query("bee_count")) return notify_fail("��ϧ�����䶼���ˣ��޷������ˡ�\n");
		if (!query("open")) return notify_fail("�����ٸð�������Ŵ򿪰ɡ�\n");
		if (query("bee_org")) return notify_fail("������������Ⱥһ��ɧ������Ȼ��֪���롣\n");
		if (query("escape")) return notify_fail("���սս������Զ���ǻ������ǲ��Ϲ�����\n");

		set("bee_org",1);
		remove_call_out("auto_check");
		bees = new("/kungfu/class/gumu/npc/white_bee");
		set("bees",bees);
		
		bee_life = lvl*(20+20*(query_amount()-1)/4);
		bees->set("jing",bee_life);
		bees->set("max_jing",bee_life);
		bees->set("eff_jing",bee_life);
		bees->set("qi",bee_life);
		bees->set("max_qi",bee_life);
		bees->set("eff_qi",bee_life);
		bees->set("jingli",bee_life);
		bees->set("max_jingli",bee_life);
		bees->set("eff_jingli",bee_life);

		lvl = lvl*3/2 + lvl*(query_amount()-1)/5;
		bees->set_skill("dodge",lvl);
		bees->set_skill("parry",lvl);
		bees->set_skill("unarmed",lvl);
		bee_exp = lvl*lvl*lvl/10;
		bees->set("combat_exp",bee_exp);
	
		if( bee_exp < 4000){
			bees->set_temp("apply/attack", 35);
			bees->set_temp("apply/damage", 15);
			bees->set_temp("apply/armor", 100);
		}
		else if( bee_exp < 30000){
			bees->set_temp("apply/attack", 45);
			bees->set_temp("apply/damage", 26);
			bees->set_temp("apply/armor", 100);
		}
		else if( bee_exp < 60000){
			bees->set_temp("apply/attack", 45);
			bees->set_temp("apply/damage", 36);
			bees->set_temp("apply/armor", 120);
		}
		else if( bee_exp < 300000){
			bees->set_temp("apply/attack", 55);
			bees->set_temp("apply/damage", 46);
			bees->set_temp("apply/armor", 130);
		}
		else{
			bees->set_temp("apply/attack", 65);
			bees->set_temp("apply/damage", 55);
			bees->set_temp("apply/armor", 150);
		}
		
		bees->set("owner",me);
		bees->set_amount(query_amount());
		bees->move(environment(me));
		message_vision(WHT"��Ȼ��$N���������˵ĵ�����������������ʱ��Ϊ��΢��������$N��������һ����ǰһ����������ص�������ȻԽ��Խ�졣\n"NOR
			+WHT"�������������֮��������$N���е��������һƬ����һ�ᣬ�����������˳������ۼ���������ٲȻ����\n"NOR, me);

		return 1;
	}
	else{
		if( query("owner") != me ) return notify_fail("��������Ⱥ��\n");
		if (!query("bee_org")) return notify_fail("���Ϳ�ˣ�\n");
		if( environment(query("bees")) != environment(me))
			return notify_fail("������Ⱥ�����������\n");
		
		message_vision(WHT"$N�������ɢ��ȥ���������ǵĹ�����\n"NOR, me);

		set("bee_org",0);
		destruct(query("bees"));
		remove_call_out("auto_check");
		call_out("auto_check", TICK+random(R_TICK) );

		return 1;
	}
}

int do_direct(string arg)
{
	object me = this_player();
	int bee_lvl = me->query_skill("bee-training",1);
	int r;
	int g_exp,g_pot,g_bee,g_mi;

	if(!arg || arg != "bee" ) return 0;
	if(me->is_busy()) return notify_fail("����æ���أ�\n");
	if(query("owner") != me ) return notify_fail("��Щ���������䣡\n");
	if(bee_lvl<30) return notify_fail("�㻹û����ѵ����䡣\n");
	if(!query("open")) return notify_fail("�����Ȱ����ų����ɡ�\n");
	if(query("bee_training")) return notify_fail("������ѵ����䡣\n");
	if(query("bee_org")) return notify_fail("�����ڵ������ս���ء�\n");
	if(me->query("jingli") <T_COST+10) return notify_fail("��̫���ˣ���Ϣ��ɡ�\n");
	
	message_vision(WHT"$N���ﲻ�Ϸ�����������ָ��������Ч�ʵĲ��ۡ�\n"NOR, me);
	set("bee_training",1);

/*	
	r = query_amount();
	g_exp = to_int((T_EXP+random(R_EXP + bee_lvl/20))*pow(r,0.5));
	g_pot = to_int((T_POT+random(R_POT + bee_lvl/40))*pow(r,0.5));
	g_bee = (T_BEE+random(R_BEE))*r;

	set("bee_training",1);
	if (query("mi_left") && query("mi_lvl")<MAX_MI*query_amount() ) {
		me->receive_damage("jingli", ramdom(T_COST*2), "��������ˣ�");
		me->add("combat_exp",g_exp);
		me->add("potential",g_pot);
		if(me->query("potential")>me->query("max_potential"))
			me->set("potential",me->query("max_potential"));
		me->improve_skill("bee-training", g_bee, 0);
	}
*/
	
	r = random(RDM);
	if (r >= RDM - query_amount()){
		remove_call_out("killer_show");
		call_out( "killer_show",1,me );
	}
	else if (r==1) {
		message_vision("$N����һЩ�����һ���ط���ֵ����ţ�Ҳ����ʲôҩ�Ŀ��Բ�(cai yao)�ɡ�\n",me);
		environment(me)->set("yaocai_h",1);
	}
	else {
		me->receive_damage("jingli", random(T_COST*2), "��������ˣ�");
		me->start_busy(1+random(2));
	}
	return 1;
}

void killer_show(object me)
{
	object ob,here;
	object *target_list;
	int i;

	if( !me ) return;
	here = environment(me);

	if(!here)return;
	if( strsrch(base_name(here), "/d/") == -1 ) return;

	if( me->is_fighting() ) return;

	target_list = filter_array(livings(), "is_suitable", this_object(), me);
	if( sizeof(target_list) == 0 ) {
		  // try again in 5 secs.
//		call_out("killer_show", 5, me);
		return;
	}

	do
	{
		i = random(sizeof(target_list));
		if(present(base_name(target_list[i]) + ".c",environment(this_object())))continue;
		ob=new( base_name(target_list[i]) + ".c" );
	}
	while( !objectp(ob) );

	ob->move(here);
	setup_skill(me,ob);
	
	message_vision(HIR"\n$N�����Ƶ����˹���!\n"NOR, ob);
	if (ob->query("family/family_name") == "ȫ����") 
		message_vision(CYN"$N�����㲻м��˵������Ҳ��������ͽ������̳�������������\n"NOR, ob);
	else if (ob->query("gender") == "����")
		message_vision(CYN"$N��ƤЦ����˵������˵��Ĺ��ȫ�ǽ��εε�С���˶���"
			+ RANK_D->query_self(ob) + "��������һ�����ա�\n"NOR, ob);
	else
		message_vision(CYN"$N��ƤЦ����˵������˵��Ĺ��ȫ�ǽ��εε�С���˶���"
			+ RANK_D->query_self(ob) + "����������̹������˵��ؼ���\n"NOR, ob);
	message_vision(CYN"$N������Ȼ��ŭ��\n"NOR,me);

	call_out("action",1,me,ob);

//	if( random(3) == 1)
//	{
//		remove_call_out("killer_show");
//		call_out( "killer_show",30+random(15),me );
//	}
}

private int is_suitable(object victim, object killer)
{
	string *no_kill_list = ({
		"mu ren",
		"huang zhen",
		"juexin dashi",
		"fighter dummy",
		"du e",
		"du nan",
		"du jie",
		"xie yanke",
		"ren woxing",
		"yue buqun",
		"qiu chuji",
		"gao lao",
		"ai lao",
		"hong qigong",
		"zhang sanfeng",
		"zuo lengchan",
		"ouyang zhan",
		"seng bing",
		"huang yaoshi",
		"yideng dashi",
		"ma guangzuo",
		"black gargoyle",
		"white gargoyle",
		"tang nan",
		"lao chaofeng",
	});

	if(  !clonep(victim) || userp(victim)
		|| victim->query("race") != "����"
		|| ( victim->query("shen") > 0 && victim->query("family/family_name") != "ȫ����" )
		|| victim->query("winner")
		|| strsrch(base_name(victim), "/kungfu/skill/") != -1
		|| strsrch(base_name(victim), "/kunfu/class/huashan") != -1
		|| strsrch(base_name(victim), "/clone/") != -1
		|| strsrch(base_name(victim), "/u/") != -1
		|| strsrch(base_name(victim), "/d/xiakedao/") != -1
		|| strsrch(base_name(victim), "/d/city/") != -1
		|| strsrch(base_name(victim), "/d/bwdh/") != -1
		|| victim->query("combat_exp") < killer->query("combat_exp") * 1/15
		|| victim->query("combat_exp") > killer->query("combat_exp")*7/3
		|| member_array(victim->query("id"), no_kill_list) != -1 || random(2)==0 )
	{
		return 0;
	}
	
	return 1;
}

void action(object me, object ob)
{
	object owner, here = environment(me);
	if( !me || !ob || !present(ob->query("id"),here) )
	{
		do_leave(ob);
		return;
	}

	if( me->is_busy() || ob->is_busy() || ob->is_fighting() 
		|| me->is_fighting() || !living(me) || !living(ob) )
	{
		 call_out("action",2,me,ob);
		 return;
	}

	message_vision(HIR"\n$N��$n�ȵ����󵨿�ͽ�����ҵ���Ĺ����Ұ�����У�\n"NOR, me,ob);
	me->kill_ob(ob);
	ob->kill_ob(me);

	call_out("do_leave",20,ob);
	return;
}

void do_leave(object ob)
{
	remove_call_out("do_leave");

	if( objectp(ob) ){
		if( ob->is_busy() || ob->is_fighting()){
			message_vision("$N���һ��������սȦ��\n",ob);
			message_vision("$N˵����û�뵽��Ĺ���ֵ�����ôӲ��"+RANK_D->query_self(ob)+"����������̣�\n",ob);
		}
		if(!living(ob))ob->revive(0);
		message_vision("$N����ææ�뿪�ˡ�\n",ob);
		destruct(ob);
	}
}

void setup_skill(object me,object obj)
{
	mapping skills;
	string *names;
	int level,i;

	if(!objectp(me) || !objectp(obj) )return;

	if( obj->query("combat_exp") < me->query("combat_exp") )
		obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(60) )  );

	level = pow( obj->query("combat_exp")*10.,0.33333 );
	if(level < 10) level = 10;

	if( obj->query("combat_exp") < 4000 )
		level = level/3 + random(level/3);
	else if( obj->query("combat_exp") < 30000)
		level = level/3 + random(level/4);
	else if( obj->query("combat_exp") < 60000)
		level = level/3 + random(level/4);
	else if( obj->query("combat_exp") < 300000)
		level = level/3 + random(level/5);
	else
		level = level/3 + random(level/6);

	skills = obj->query_skills();
	names = keys(skills);

	for (i=0; i<sizeof(names); i++) {
		obj->set_skill(names[i], level);
	}

	call_out("do_leave",60+random(60),obj);
}

int do_add(string arg)
{
	object me = this_player();
	int i,max,mi_lvl;

	if( !wizardp(me) ) return 0;
	if(!arg) return 0;

	sscanf(arg, "%d", i);
	set("mi_lvl",query("mi_lvl") + i);
	mi_lvl = query("mi_lvl");
	max = MAX_MI*query_amount();
	tell_object(me, "����"+chinese_number(max)+"������"	+ chinese_number(mi_lvl)+"��\n");
	
	return 1;
}

void destroy_me(object me)
{
	if (query("owner"))	return;

	remove_call_out("destroy_me");
	remove_call_out("auto_check");
	remove_call_out("killer_show");

	destruct(me);
}

int do_cai(string arg)
{
	object me = this_player();
	object here = environment(me);
	int i;
	object yaocai;

	if ( !arg && arg != "yao" ) return 0;
	if ( !here->query("yaocai") && !here->query("yaocai_h") ) return 0;

	if (here->query("yaocai")){
		here->set("yaocai",0);
		switch (random(5)){
		case 0 : yaocai = new("/clone/herb/chantui");
			break;
		case 1 : yaocai = new("/kungfu/class/gumu/herb/muxiang");
			break;
		case 2 : yaocai = new("/kungfu/class/gumu/herb/shengma");
			break;
		case 3 : yaocai = new("/kungfu/class/gumu/herb/chaihu");
			break;
		case 4 : yaocai = new("/kungfu/class/gumu/herb/shanju");
			break;
		}
		yaocai->move(me);
		message_vision("$N�����Ӳݷ�����"+yaocai->query("name")+"��\n", me);
	}
	if (here->query("yaocai_h")){
		here->set("yaocai_h",0);
		switch (random(3)){
		case 0 : yaocai = new("/clone/herb/renshen");
			break;
		case 1 : yaocai = new("/clone/herb/heshouwu");
			break;
		case 2 : yaocai = new("/kungfu/class/gumu/herb/tufuling");
			break;
		}
		yaocai->move(me);
		message_vision("$N�����Ӳݷ�����"+yaocai->query("name")+"��\n", me);
	}
	return 1;
}