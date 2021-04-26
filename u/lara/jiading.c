// Code of ShenZhou
//ָ��yapu_npc�ļҶ�
//maco
//mantian fix �Ҷ��ϴ��˵�BUG may/11/2001
//Lara 2001/11/20
inherit NPC;
#include <ansi.h>
int ask_yapu();

void create()
{
	set_name("�Ҷ�", ({ "jia ding", "ding" }));
	set("long", "һ����ʮ��ͷ��С���ӣ�����ʵ��˫Ŀ�����ƺ��������깦��\n");
	set("gender", "����");
	set("age", 25);

	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("stick", 30);
	set_skill("staff", 30);
	set_skill("sword", 30);
	set_skill("blade", 30);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("inquiry", ([
		"����" : (:ask_yapu:),
		"yapu" : (:ask_yapu:),
	]));
	create_family("�һ���", 4, "�Ҷ�");
	delete("title");
	setup();
}

int start_check(object me)
{
		call_out("leave", 1200, me);
		call_out("check", 1, me);
}

void init()
{
	::init();

	add_action("do_recognize", "ren");
	add_action("do_recognize", "recognize");
	add_action("do_bring", "bring");
	add_action("do_bring", "dai");
	add_action("do_order", "order");

}
void leave(object me)
{
	string killer = me->query_temp("my_killer");
	object jiading = this_object();

	if (query("recognized") && objectp(present(me, environment(jiading)))) {
	command("addoil "+jiading->query("job_master"));
	call_out("leave", 60, me);
	}

	else if(objectp(present(me, environment(jiading)))){
	message_vision(CYN"$N˵��������û�׽������"+query("find_yapu_real")+"װ�ɵ�"+query("find_yapu")+"���ҿ������Ǵ��������ˣ������Ȼع���ׯ�ɡ�\n"NOR,jiading);
	command("sigh");
	message_vision("$N�첽�뿪�ˡ�\n"NOR,jiading);
	destruct(jiading);
	}

	else {
	message_vision("$N�첽�뿪�ˡ�\n"NOR,jiading);
	destruct(jiading);
	}

	return;
}

void check(object me)
{
	string killer = me->query_temp("my_killer");
	object jiading = this_object();

	if(!me->query("find_yapu"))
	{
	command("bye "+me->query("id"));
	message_vision("$N�첽�뿪�ˡ�\n"NOR,jiading);
	destruct(jiading);
	}

	else if(me->is_ghost() )
	{
	command("ah");
	command("cry corpse");
	command("grpfight "+me->query_temp("my_killer"));
	command("kill "+me->query_temp("my_killer"));
	}
	else call_out("check", 1, me);
}

int do_recognize(string arg)
{
	object me, ob, jiading, where, weapon, huwei;
	mapping skill_status;
	string *sname;
	int i ,num, level = 0, s_level, j, gain, exp, ob_exp, rate;

	me = this_player();
	exp = me->query("combat_exp");

	jiading = this_object();
	if( query("job_master") != me->query("id"))
		return 0;
	if( query("recognized"))
		return notify_fail("�Ҷ��Ѿ�ָ�ϳ����Է��ˣ�\n");
	if( !living(jiading) )
		return notify_fail("��....����ȰѼҶ�Ū����˵��\n");
	if( !arg )
		return notify_fail("��Ҫ�Ҷ�ָ��˭��\n");
	if(!objectp(ob = present(arg, environment(this_player()))))
		return notify_fail("����û������ˡ�\n");
	if(ob->query("th_victim"))
		return notify_fail(ob->name()+"�Ѿ���ָ�ϳ����ˣ�\n");
	if(ob == me)
		return notify_fail("ָ�����Լ�����������\n");
	if(ob == jiading)
		return notify_fail("Ҫ�Ҷ�ָ�ϼҶ���\n");
	if(ob->query("family/family_name") == "�һ���")
		return notify_fail("�����һ���������Ҳ�ϲ�������\n");
	if( me->is_busy() || me->is_fighting() )
		return notify_fail("����æ���ء�\n");
	if( jiading->is_busy() || jiading->is_fighting() )
		return notify_fail( "�Ҷ���æ���ء�\n");
	if(environment(me)->query("no_fight"))
		return notify_fail("���ﲻ��ս�����ϳ���Ҳû�á�\n");


	me->start_busy(1);

	message_vision("$N�����ڼҶ�����˵�����ǲ������"+ob->name()+"��\n",me,ob);
	where = environment(ob);

	if (ob->query("yapu_target") == me->query("id") 
	&& ob->query("name") == query("find_yapu") )
	{
	if( !living(ob) )
	ob->revive();
	command("ah");
	command("points "+ob->query("id"));
	ob->interrupt_me();
	ob->set("real_face",1);
	set("recognized",1);

	//yapu_npc����ָĻ�
	{
	ob->set("long",ob->query("real_long"));
	if(ob->query("real_title"))
	ob->set("title",ob->query("real_title"));
	ob->clear_condition();
	ob->set("shen_type", -1);
	
	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if ( skill_status[sname[i]] > level ) level = skill_status[sname[i]];
		}
		
		level = (int)level*4/5 + 1;
		s_level = (int)level*21/20;

		rate = random(3)+9;

		ob->set("combat_exp", exp*rate/10 + random(exp/100) );
		ob_exp = ob->query("combat_exp");

		ob->set("th_victim", me->query("id"));
		//��npc��reward
		
		ob->set("gain", 50 + level);
		gain = ob->query("gain");
		if(gain>400) gain=400;//�������

		if(exp <  100000) //100k
			gain = gain + random(level/2);
		else if(exp <  800000) //800k
			gain = gain + random(level/3);
		else if(exp < 2700000) //2.7m
			gain = gain + random(level/4);
		else if(exp < 6400000) //6.4m
			gain = gain + random(level/5);
		else gain = gain + random(level/8);

		ob->set("gain_exp", gain*11/10);      //���10%�ı���
		ob->set("gain_pot", gain/3 +random(gain/10));//��ߵ�Ǳ�ܵı���
		ob->set("shen",-ob_exp/10);
		
		if(ob_exp < 1000000) {
		ob->add("gain_exp", random(5)+10);
		ob->add("gain_pot", random(5)+1);
		}
		else if(ob_exp < 2000000) {
		ob->add("gain_exp", random(5)+15);
		ob->add("gain_pot", random(5)+5);
		}
		else if(ob_exp < 3000000) {
		ob->add("gain_exp", random(5)+20);
		ob->add("gain_pot", random(5)+10);
		}
		else {
		ob->add("gain_exp", random(5)+25);
		ob->add("gain_pot", random(5)+15);
		}


		ob->set("max_qi", me->query("max_qi")*9/10);
		ob->set("eff_qi", me->query("max_qi")*9/10);
		ob->set("max_jing", me->query("max_jing")*9/10);
		ob->set("eff_jing", me->query("max_jing")*9/10);
		ob->set("qi", ob->query("max_qi"));
		ob->set("jing", ob->query("max_jing")*9/10);
		ob->set("jiali", me->query("jiali")/3);//���ͼ���1/2->1/3
		if ( me->query("max_neili") > 0 ) {
			ob->set("max_neili", level*20); //����*30����ֵ�ˣ����ڸ�Ϊ20
			if(ob->query("max_neili") > me->query("max_neili") )
				ob->set("max_neili", me->query("max_neili")+level );
		}
		else ob->set("max_neili", 500);
		
		if ( me->query("max_jingli") > 0 ) {
			ob->set("max_jingli", me->query("max_jingli")*9/10);
		}
		else ob->set("max_jingli", 500);
		ob->set("neili", ob->query("max_neili"));
		ob->set("jingli", ob->query("max_jingli"));
		ob->set("no_sing", 1);
		ob->set_skill("dodge", level);
		ob->set_skill("parry", level );
		ob->set_skill("force", level);
		
	switch (ob->query("real_menpai")) {
	case "huashan" :
	ob->set_name("���", ({"da dao", "dao" ,"robber"}) );
	ob->set_skill("blade", s_level);
	ob->set_skill("sword", s_level);
	ob->set_skill("cuff", s_level);
	ob->set_skill("strike", s_level);
	ob->set_skill("huashan-jianfa", level);
	ob->set_skill("liangyi-dao", level);
	ob->set_skill("ding-dodge", s_level);
	ob->set_skill("zixia-gong", level);
	ob->set_skill("pishi-poyu", level);
	ob->set_skill("hunyuan-zhang", level);
	ob->set_skill("ziyin-yin", level);
	ob->set_skill("zhengqi-jue", level);

	ob->map_skill("force", "zixia-gong");
	ob->map_skill("dodge", "ding-dodge");
	ob->map_skill("parry", "huashan-jianfa");
	ob->map_skill("strike", "hunyuan-zhang");
	ob->map_skill("cuff", "pishi-poyu");
	ob->map_skill("sword", "huashan-jianfa");
	ob->map_skill("blade", "liangyi-dao");
	ob->prepare_skill("cuff", "pishi-poyu");
	ob->prepare_skill("strike", "hunyuan-zhang");
	ob->set("real_message", HIR"С����ɫһ�䣬�ȵ���"+RANK_D->query_rude(me)+"ԭ���ǻ���а���£���׽"+RANK_D->query_self_rude(ob)+"����û�������ף�\n"NOR);
	ob->add("gain_exp", random(10)+30);
	ob->add("gain_pot", random(5)+20);
	ob->add_money("gold", random(2));
	if(random(3) == 1)  weapon=new("/clone/weapon/gangdao");
	else if(random(3) == 1) weapon=new("/clone/weapon/changjian");
	
		break;
		
	case "dajin" :
	ob->set_name("ɱ��", ({"shashou", "shou", "killer"}) );
	ob->set_skill("sword", s_level);
	ob->set_skill("cuff", s_level);
	ob->set_skill("taiji-shengong", s_level);
	ob->set_skill("taiji-jian", s_level);
	ob->set_skill("tiyunzong", level);
	ob->set_skill("taiji-quan", s_level);
	ob->set_skill("taoism", level);
	ob->set_skill("literate", level);
	ob->map_skill("force", "taiji-shengong");
	ob->map_skill("parry", "taiji-jian");
	ob->map_skill("cuff", "taiji-quan");
	ob->map_skill("dodge", "tiyunzong");
	ob->map_skill("sword", "taiji-jian");
	ob->prepare_skill("cuff", "taiji-quan");
	ob->set("real_message", HIR"������Цһ��������"+RANK_D->query_rude(me)+"���ص�ǰ��������\n"NOR);
	ob->set("jiali", 0);
	ob->set("str", 27+random(4));
	ob->carry_object("/clone/anqi/feibiao")->set_amount(2+random(3));
	if(random(3) != 0) weapon=new("/clone/weapon/changjian");
		break;
		
	case "tiezhang" :
	ob->set_name("���", ({"e ba", "ba"}) );
	ob->set_skill("strike", s_level+20);
	ob->set_skill("blade", s_level);
	ob->set_skill("taixuan-gong", level);
	ob->set_skill("tie-zhang", s_level+20);
	ob->set_skill("ding-dodge", s_level);
	ob->set_skill("wuhu-duanmen", s_level);
	ob->map_skill("blade","wuhu-duanmen");
	ob->map_skill("dodge","ding-dodge");
	ob->map_skill("strike","tie-zhang");
	ob->map_skill("force", "taixuan-gong");
	ob->map_skill("parry", "tie-zhang");
	ob->prepare_skill("strike", "tie-zhang");
	ob->add("gain_exp", -20);
	ob->add("gain_pot", -20);
	ob->add_money("silver", 20+random(31));
	ob->set("real_message", HIR"�����ֳ���һ�������϶���ɱ������$N���˹�����\n"NOR);
		break;
		
	case "shaolin" :
	ob->set_name("�ƽ�ɮ", ({"pojie seng", "seng"}) );
	ob->set_skill("blade", s_level);
	ob->set_skill("sword", s_level);
	ob->set_skill("club", s_level);

	ob->set_skill("buddhism", level);
	ob->set_skill("damo-jian", s_level);
	ob->set_skill("xiuluo-dao", s_level);
	ob->set_skill("zui-gun", s_level);
	ob->set_skill("jingang-quan", s_level);
	ob->set_skill("shaolin-shenfa", level);
	ob->set_skill("hunyuan-yiqi", level);
	ob->set_skill("yizhi-chan", level);
	ob->set_skill("banruo-zhang", level);
	ob->map_skill("force", "hunyuan-yiqi");
	ob->map_skill("dodge", "shaolin-shenfa");
	ob->map_skill("parry", "damo-jian");
	ob->map_skill("cuff","jingang-quan");
	ob->map_skill("sword", "damo-jian");
	ob->map_skill("blade", "xiuluo-dao");
	ob->map_skill("club", "zui-gun");
	ob->set("real_message", HIR"ɮ����ɫһ�䣬��Ц�������ۣ����Ȼ�ϳ���"+RANK_D->query_self_rude(ob)+"���������㲻�ã�\n"NOR);
		switch (random(3)) {
		case 0 :
			ob->set_skill("finger", s_level);
			ob->set_skill("yizhi-chan", s_level);
			ob->set_skill("strike", s_level);
			ob->set_skill("banruo-zhang", s_level);
			ob->map_skill("finger","yizhi-chan");
			ob->map_skill("strike","banruo-zhang");
			ob->prepare_skill("finger","yizhi-chan");
			ob->prepare_skill("strike","banruo-zhang");
			if(random(3) == 0) weapon=new("/d/shaolin/npc/obj/jiedao");
			break;
		case 1 :
			ob->set_skill("cuff", s_level);
			ob->set_skill("jingang-quan", s_level);
			ob->map_skill("cuff","jingang-quan");
			ob->prepare_skill("cuff","jingang-quan");
			if(random(3) == 0) {
			ob->apply_condition("drunk", ob->query("con") + ob->query("max_neili")/100 + 3);
			weapon=new("/d/shaolin/npc/obj/qimeigun");
				}
			break;
		case 2 :
			ob->set_skill("claw", s_level);
			ob->set_skill("longzhua-gong", s_level);
			ob->map_skill("claw","longzhua-gong");
			ob->prepare_skill("claw","longzhua-gong");
			break;
		}
		break;
		
	case "xiyu" :
	ob->set_name("�ɹ��佫", ({"menggu wujiang", "wujiang", "jiang"}) );
	ob->set("class", "officer");
	ob->set("dali/rank",3);
	ob->set("rank_info/rude", "������");
	ob->set_skill("hamagong", s_level+10);
	ob->set_skill("lingshe-zhang", s_level);
	ob->set_skill("wuxingbu", s_level);
	ob->set_skill("luan-blade", s_level);
	ob->set_skill("blade", s_level);
	ob->set_skill("strike", s_level);
	ob->set_skill("parry", s_level);
	ob->set_skill("shentuo-zhang", s_level);
	ob->set_skill("lingshe-quan", s_level);

	ob->map_skill("force", "hamagong");
	ob->map_skill("blade", "luan-blade");
	ob->map_skill("dodge", "wuxingbu");
	ob->map_skill("parry", "luan-blade");
	
	ob->set("real_message", "");
	message_vision(HIR"����˫��һ�⣬��Ц������ƾ����"+RANK_D->query_rude(me)+"��Ҳ���"+RANK_D->query_self_rude(ob)+"���ԣ�\n"NOR, me, ob);

	{
	num = 1+random(3);
	message_vision(HIR"�����������֣�����ͻȻԾ��"+chinese_number(num)+"�����׻�����"+chinese_number(num+1)+"����$N���Ұ�����\n"NOR, me, ob);
		    for (i=0; i<num; i++) {
		huwei = new("/d/taohua/npc/mg_huwei");
		huwei->set("combat_exp", exp/2 + random(exp/1000) );
		huwei->set("rank_info/rude", "������");
		huwei->set("max_qi", ob->query("max_qi")/2);
		huwei->set("eff_qi", ob->query("max_qi")/2);
		huwei->set("max_jing", ob->query("max_jing")/2);
		huwei->set("eff_jing", ob->query("max_jing")/2);
		huwei->set("qi", huwei->query("max_qi"));
		huwei->set("jing", huwei->query("max_jing"));
		huwei->set("jiali", ob->query("jiali")/2);
		huwei->set("max_neili", ob->query("max_neili")/2);
		huwei->set("max_jingli", ob->query("max_jingli")/2);
		huwei->set("neili", huwei->query("max_neili"));
		huwei->set("jingli", huwei->query("max_jingli"));

		huwei->set_skill("ding-force", level*3/4);
		huwei->set_skill("san-sword", level*3/4);
		huwei->set_skill("ding-dodge", level*3/4);
		huwei->set_skill("luan-blade", level*3/4);
		huwei->set_skill("wrestling", level*3/4);
		huwei->set_skill("hand", level*3/4);
		huwei->set_skill("force", level*3/4);
		huwei->set_skill("parry", level*3/4);
		huwei->set_skill("dodge", level*3/4);
		huwei->set_skill("sword", level*3/4);

		huwei->map_skill("force", "ding-force");
		huwei->map_skill("sword", "san-sword");
		huwei->map_skill("dodge", "ding-dodge");
		huwei->map_skill("parry", "san-sword");
		huwei->map_skill("hand", "wrestling");
		huwei->prepare_skill("hand", "wrestling");
		huwei->add_money("silver", 20+random(50));

		huwei->move(environment(me));
		
		huwei->kill_ob(me);
		huwei->start_check(ob);
		huwei->set_leader(ob);
		me->fight_ob(huwei);
		ob->add("gain_exp", random(10)+30);//��ߴ˴��ı���
		ob->add("gain_pot", random(5)+15); //��ߴ˴��ı���
		}
	}
	ob->add_money("silver", 20+random(50));
	if(ob->query_temp("armor/cloth"))
	destruct(ob->query_temp("armor/cloth"));
	ob->carry_object("/clone/armor/tiejia")->wear();
	if(random(3) == 0) weapon=new("/clone/weapon/gangdao");
	if(random(me->query("combat_exp")) > 2000000) {
	ob->map_skill("strike", "hamagong");
	ob->prepare_skill("strike", "hamagong");
	ob->add("gain_exp", random(10)+40);
	ob->add("gain_pot", random(5)+10);
	}
	else {
	ob->map_skill("cuff","lingshe-quan");
	ob->map_skill("strike","shentuo-zhang");
	ob->prepare_skill("cuff","lingshe-quan");
	ob->prepare_skill("strike","shentuo-zhang");
	}

		break;
		
	case "mizong" :
	ob->set_name("��������", ({"hufa lama", "hufa", "lama"}) );
	ob->set("class", "lama");
	ob->set_skill("longxiang-banruo", level);
	ob->set_skill("shenkongxing", level);
	ob->set_skill("huoyan-dao", s_level);
	ob->set_skill("yujiamu-quan", level);
	ob->set_skill("dashou-yin", s_level);
	ob->set_skill("lamaism", level);
	ob->set_skill("xue-dao", s_level);
	ob->set_skill("mingwang-jian", s_level);
	ob->set_skill("jingang-chu", level);
	ob->set_skill("staff", level);
	ob->set_skill("sword", s_level);
	ob->set_skill("blade", s_level);
	ob->set_skill("cuff", s_level);
	ob->set_skill("hand", s_level);
	ob->set_skill("strike", s_level);
	ob->map_skill("force", "longxiang-banruo");
	ob->map_skill("dodge", "shenkongxing");
	ob->map_skill("parry", "xue-dao");
	ob->map_skill("blade", "xue-dao");
	ob->map_skill("sword", "mingwang-jian");
	ob->map_skill("staff", "jingang-chu");
	ob->set("real_message", HIR"���$NĿ�����������Ϻ�Ȼ��������ɲ����е���"+RANK_D->query_rude(me)+"���һ������ģ�\n"NOR);
	
	if(ob->query_temp("armor/cloth"))
	destruct(ob->query_temp("armor/cloth"));
	
	ob->carry_object("/d/qilian/obj/lamajiasha")->wear();
	if(random(6) == 0) weapon=new("/clone/weapon/changjian");
	else if(random(5) == 1)	weapon=new("/d/xueshan/obj/miandao");
	else if(random(4) == 2) weapon=new("/d/xueshan/obj/fachu");

	if(random(me->query("combat_exp")) > 2000000) {
	ob->map_skill("strike", "huoyan-dao");
	ob->prepare_skill("strike", "huoyan-dao");
	ob->add("gain_exp", random(20)+50);
	ob->add("gain_pot", random(10)+20);
	}
	else {
	ob->map_skill("hand", "dashou-yin");
	ob->map_skill("cuff", "yujiamu-quan");
	ob->prepare_skill("hand", "dashou-yin");
	ob->prepare_skill("cuff", "yujiamu-quan");
	}
		break;
	case "miaojiang" :
	ob->set_name("�置��Ů", ({"miaojiang wunu", "wunu", "nu"}) );
	ob->set_skill("claw", s_level);
	ob->set_skill("strike", s_level);
	ob->set_skill("huagong-dafa", level);
	ob->set_skill("zhaixinggong", level);
	ob->set_skill("chousui-zhang", s_level);
	ob->set_skill("sanyin-zhua", s_level);
	ob->set_skill("feixing-shu", s_level);
	ob->set_skill("poison", level/3);//���Լ�Ϊ1/3
	ob->set_skill("dodge", s_level);

	ob->map_skill("force", "huagong-dafa");
	ob->map_skill("strike", "chousui-zhang");
	ob->map_skill("claw", "sanyin-zhua");
	ob->map_skill("dodge", "zhaixinggong");
	ob->map_skill("parry", "sanyin-zhua");
	ob->prepare_skill("strike", "chousui-zhang");
	ob->prepare_skill("claw", "sanyin-zhua");

	ob->set("real_message", "");
	message_vision(HIR"Ů������һת��΢Ц������λ"+RANK_D->query_respect(me)+"����ò���Ҫ׽�Ұɣ��ǡ����ҿ�Ҫ�������ӡ�\n"NOR, me);
	
	ob->carry_object("/clone/drug/xxqingxin-san");
	ob->carry_object("/d/xingxiu/obj/lianxin");
	ob->carry_object("/d/xingxiu/obj/blzhen")->set_amount(1+random(3));

	if(ob->query_temp("armor/cloth"))
	destruct(ob->query_temp("armor/cloth"));
	ob->carry_object("/d/city/obj/jin_ao")->wear();
	//has poison,add reward
	ob->add("gain_exp", random(10)+30);
	ob->add("gain_pot", random(5)+10);

	if(random(me->query("combat_exp")) > 2000000 && ob->query_skill("strike") > 250 && ob->query("neili") > 1000 && random(2) == 1) {
	message_vision("$N����ѷŵ��ڱߣ�����һ����ֻ��һ�󼫼⼫ϸ��������ԶԶ���˳�ȥ��\n", ob);
	message_vision(HIR"�����������������ͻȻ�ɳ���ӡӡ��һ����ǣ����Ƕ���Ϩ���漴���������һ���죬�����գ�������������Ż������䡣\n"NOR, me);
	new("/d/xingxiu/obj/flute_fire")->move(environment(me));
	ob->add("gain_exp", random(20)+50);
	ob->add("gain_pot", random(10)+30);
	}

		break;

	}
		if(weapon != 0) {
		weapon->move(ob);
		weapon->wield();
		}
		//�趨���
		message_vision(""+ob->query("real_message")+"", me, ob);
		ob->kill_ob(me);
		me->fight_ob(ob);

	}

	}
	//�Ļ����
	}
	else if (ob->query("name") == query("find_yapu"))
	{
	command("shake");
	command("say ����࣬�������ǡ�");
	}

	else if (ob->query("race") != "����" )
	{
	command("consider");
	command("say ������"+query("find_yapu_real")+"�����ˣ����޲��磬�ô�Ҳ���Ǹ����ġ�����");
	}

	else if (ob->query("gender") == "Ů��" && ob->query("per") >= 30 && ob->query("age") < 30)
	{
	message_vision("�Ҷ������ؿ���$n����\n",me,ob);
	command("shake");
	command("say ��λ"+ RANK_D->query_respect(me) +"����һ��������������Ǹ�"+query("find_yapu_real")+"��");
	}
	else if (ob->query("gender") == "����" && ob->query("per") >= 30)
	{
	command("shake");
	command("say ��λ"+ RANK_D->query_respect(me) +"�Ǳ����ã�������"+query("find_yapu_real")+"���Ա��⣿");
	}
	else
	{
	command("shake");
	command("say ���ǲ��ǡ�");
	}
	return 1;

}

int do_bring(string arg)
{
	object me, ob, jiading, where, weapon;
	int yapu_exp, yapu_pot;
	string lu;
	me = this_player();
	jiading = this_object();

	if( query("job_master") != me->query("id"))
		return 0;
	if( !living(jiading) )
		return notify_fail("��....����ȰѼҶ�Ū����˵��\n");
	if( !arg )
		return notify_fail("��Ҫ�Ҷ�����˭��\n");
	if(!objectp(ob = present(arg, environment(this_player()))))
		return notify_fail("����û������ˡ�\n");
	if(ob == me)
		return notify_fail("�����Լ����㵽������ʲ�᣿\n");
	if(ob == jiading)
		return notify_fail("Ҫ�Ҷ����߼Ҷ���\n");
	if(ob->query("th_victim") != me->query("id"))
		return notify_fail("���޷�ȷ��"+ob->name()+"�ǲ�����Ҫ׽�Ķ���\n");
	if( me->is_busy() || me->is_fighting() )
		return notify_fail("����æ���ء�\n");
	if( jiading->is_busy() || jiading->is_fighting() )
		return notify_fail( "�Ҷ���æ���ء�\n");

	switch (me->query("family/master_name")) {
	case "��ҩʦ" :
	lu = "��½ʦ��";
	break;
	default:
	lu = "½ׯ��";
	}

	yapu_exp = ob->query("gain_exp");
	yapu_pot = ob->query("gain_pot");

	if(yapu_exp > 600) yapu_exp = 600+random(40); //���100����
	if(yapu_pot > 300) yapu_exp = 300+random(30); //���50����

	if (arg == "corpse" && (ob = present(arg, environment(me))) 
	&& ob->query("yapu_fail") == me->query("id"))
	{
	command("shrug");
	command("say ������˴����ˣ��������ˣ������Ȱ�������ȥ����ɡ�");
	message_vision("�Ҷ���"+ob->name()+"�����������ڱ��ϣ��ߵ��ˡ�\n",me,ob);
	me->delete("find_yapu");
	me->apply_condition("th_yapu_fail", 5);
	destruct(ob);
	destruct(jiading);
	}
	else if((ob = present(arg, environment(me))) && ob->query("th_victim") == me->query("id") && !living(ob)){
		message_vision(CYN"$N˵��������"+ob->name()+"�����ˣ�\n"NOR,me,ob);
		command("nod "+getuid(me));
		
		if(ob->query_temp("last_damage_from") == me && ob->query("age") < 20 && me->query("shen") > 1000 ) {
		message_vision(HIR"�Ҷ��ͳ�һ��ϸ��������С�����⿪$n����ͣ���Ҫնȥ$n����ͷ����\n"NOR,me,ob);
		message_vision(CYN"$N��Ȼ˵������������"+ob->name()+"������ᣬ��Ȼ������;������δʼ���ܸĹ���\n"NOR,me,ob);
		message_vision(CYN"$N˵�������ȱ��֣�ֱ�Ӱ�$p���ع���ׯ������"+lu+"������������ǡ�\n"NOR,me,ob);
		command("ok");
		me->add("th_exp",yapu_exp);
		me->add("th_pot",yapu_pot);
		me->set("th_help_yapu",1);
		}
		else if(ob->query_temp("last_damage_from") == me) {
		message_vision(HIR"�Ҷ��ͳ�һ��ϸ��������С�����⿪$n����ͣ��ɿ��նȥ��$n����ͷ������ת�����棬��$p˫������һ������ʱ��ѪȪӿ��\n"NOR,me,ob);
		message_vision(HIR"�Ҷ�����С����ȡ��һ����ƿ��������ҩ����$p�����˫���˴�����Ѫ���������ǴӴ�Ҳ�ѳ�����֮�ˡ�\n"NOR,me,ob);
		me->add("th_exp",yapu_exp);
		me->add("th_pot",yapu_pot);
		}
		else {
		command("say ��Ȼ����"+ RANK_D->query_respect(me) +"���ְ�ƽ�ģ����������Ǵ�����"+RANK_D->query_rude(ob)+"�ˣ�");
		me->set_temp("not_me",1);
		//��ɹ�������ûreward��
		}
	command("say �����ھͰ���"+RANK_D->query_rude(ob)+"���ع���ׯ�ϡ�");
	message_vision("�Ҷ���"+ob->name()+"�����������ڱ��ϣ��ߵ��ˡ�\n",me,ob);
	me->set("th_yapu_ok",1);

		if(me->query_temp("not_me")) {
		tell_object(me,"�˴ι��������ɻ��"+yapu_exp+"���һ�exp��"+yapu_pot+"���һ�pot��������Ϊ�������Լ���ɵģ����Բ��㡣\n");
		log_file("test/yapu_job",
		sprintf("%s(%s) failed to get %d th_exp and %d th_pot from %s on %s\n", 
		me->name(), me->query("id"), yapu_exp, yapu_pot, ob->name(), ctime(time())));
		me->delete_temp("not_me");
		}
		else {
		tell_object(me,"�˴ι������"+yapu_exp+"���һ�exp��"+yapu_pot+"���һ�pot��\n");
		log_file("test/yapu_job",
		sprintf("%s(%s) got %d th_exp and %d th_pot from %s on %s\n", 
		me->name(), me->query("id"), yapu_exp, yapu_pot, ob->name(), ctime(time())));

		}
		if(me->query("th_exp")> 50000) {
		me->set("th_exp",50000);
		tell_object(me,"����һ������Ѿ��ﵽ50000������㣬�������ۻ��ˡ�\n");
		}//���5��

		if(me->query("th_pot")>me->query("max_potential")*30) {
		me->set("th_pot",me->query("max_potential")*30);
		tell_object(me,"����һ�Ǳ���Ѿ��ﵽ"+(me->query("max_potential")*30)+"������㣬�������ۻ��ˡ�\n");
		}//���3��
		
	destruct(ob);
	destruct(jiading);
	}
	else tell_object(me,"����ȴ��"+ob->name()+"���У�\n");

	return 1;
}

string ask_yapu()
{
	object me;
	me = this_player();

	if( query("job_master") == me->query("id")) {
	return "����"+query("yapu_region")+""+query("yapu_room")+CYN"������"+query("find_yapu_real")+"ʱ�������Ǹ�Ѱ��"+query("find_yapu")+"ģ����";	
	}
	else return 0;
}

int do_order(string arg)
{
	object me, jiading;
	me = this_player();
	jiading = this_object();

	if( query("job_master") != me->query("id"))
		return 0;
	if( !living(jiading) )
		return notify_fail("��....����ȰѼҶ�Ū����˵��\n");
	if( me->is_busy() )
		return notify_fail("����æ���ء�\n");
	if( jiading->is_busy() || jiading->is_fighting() )
		return notify_fail( "�Ҷ���æ���ء�\n");

	if( arg == "follow" ) {
	message_vision("$N��Ҷ��������֣�Ҫ����������\n",me);
	command("follow "+me->query("id"));
	}
	if( arg == "stay" ) {
	message_vision("$N����Ҷ�����ԭ�ء�\n",me);
	command("nod "+me->query("id"));
	command("follow none");
	}
	if( arg == "leave" ) {
	message_vision("$N��Ҷ�һ���֣�˵���������뿪�����\n",me);
	command("nod");
	jiading->random_move();
	}
	return 1;
}