// Code of ShenZhou
// fan-ye.c ����

inherit NPC;

string ask_me();
void skill_set1(object, int);
void skill_set2(object, int);
void skill_set3(object, int);

void create()
{
	set_name("����", ({ "fan ye", "fan"}));
    set("long", "�����е���ģ����Ž��йٷ���Ŀ����棬���Ǿ����������ı�ԣ��Ӵ���Ϊ�ٶ��깦ѫ�պա�\n");
	set("title","�����˾��");
    set("gender", "����");
    set("age", 43);
    set("inquiry", ([
		"�ΰ�" : (: ask_me :),
		]));

	set_skill("cuff", 140);
    set_skill("taiji-quan", 155);
    set_skill("dodge", 150);
    set_skill("tiyunzong", 160);
    set_skill("parry", 140);
    set_skill("force", 140);
    set_skill("sword", 140);
	set_skill("ding-force",150);
	set_skill("taiji-jian",155);

    map_skill("cuff","taiji-quan");
    map_skill("dodge","tiyunzong");
	map_skill("force","ding-force");
	map_skill("sword","taiji-jian");

	prepare_skill("cuff","taiji-quan");

    set("str", 30);
    set("int", 25);
    set("con", 25);
    set("dex", 40);

    set("max_qi", 1500);
    set("qi", 1500);
    set("max_jing", 1200);
    set("jing", 1200);
    set("max_neili", 2000);
    set("neili", 2000);
	set("max_jingli", 2000);
    set("jingli", 2000);
    set("jiali", 80);
    set("combat_exp", 800000);
    set("attitude", "peaceful");
    set("shen_type", 1);
	set_temp("apply/armor", 60);
	set_temp("apply/dodge", 20);

    setup();
	carry_object("/d/dali/obj/zipao.c")->wear();	
	carry_object("/d/city/obj/gangjian.c")->wield();
}

string ask_me()
{
	object ob,  weapon, room, who=this_object(), me=this_player();
	int exp, level, i, room_no;
	string areaname;

	exp=me->query("combat_exp");
	for (level=1;level*level*level<exp*10;level++) {}
        
	if (who->query_temp("job_offered"))
		return "����������ûʲôҪ�������飬"+RANK_D->query_respect(me)+"���Ȼ�ȥ��Ϣ�ɡ�";
        
	if (!me->query("dali/employee"))
		return RANK_D->query_respect(me)+"���Ҵ������޹ϸ𣬺��д��ʰ���";

	if (environment(this_object())!=find_object("/d/dali/sangong2"))
		return "�Բ�����ֻ�ڸ��ð����񣬵��һظ�ȥ���������Ұɡ�";

	if (me->query("dali/trust")<0
		|| (me->query("family/family_name") != "����μ�"
		&& me->query("combat_exp")>3000000)) {
		command("hmm "+me->query("id"));
		return "����������ûʲôҪ�������飬"+RANK_D->query_respect(me)+"���Ȼ�ȥ��Ϣ�ɡ�";
	}

	if (me->query("combat_exp")<30000) {
		command("pat "+me->query("id"));
		command("say ������ǿ�˶���Ϊ�׺���"+RANK_D->query_respect(me)+"�������������²�������������Σ������������");
		return RANK_D->query_respect(me)+"�����Ȼ�ȥ���û����������ɡ�";
	}

	if (me->query_temp("dalijobon")) {
		return "���Ȱ�����ͷ�Ļ�����";
		}
	
	if (me->query("mud_age") - me->query("dali/lastjob") < 120) {
		return "����������ûʲôҪ�������飬"+RANK_D->query_respect(me)+"���Ȼ�ȥ��Ϣ�ɡ�";
		}

	me->set("dali/lastjob",me->query("mud_age"));
	me->set_temp("dalijobon",1);

	if (me->query("combat_exp")<500000) {
		ob = new("/d/dali/npc/dlbandit1");
		skill_set1(ob, level);
	}
	else {
		if (me->query("combat_exp")<1500000) {
			ob = new("/d/dali/npc/dlbandit2");
			skill_set2(ob, level);
		}
		else {
			ob = new("/d/dali/npc/dlbandit3");
			skill_set3(ob, level);
			}
		}

	ob->move(load_object("/d/dali/feiwo.c"));

	ob->set("combat_exp",(me->query("combat_exp")/100)*(210+random(81)));
	ob->set("shen",-ob->query("combat_exp")/100);
	ob->set("max_qi", me->query("max_qi")*(12+random(5))/10);
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("max_jing", me->query("max_jing")*(10+random(5))/10);
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	ob->set("max_neili", me->query("max_neili")*(10+random(5))/15);
	ob->set("neili", ob->query("max_neili"));
	ob->set("jiali",ob->query("max_neili")/25);
	ob->set("max_jingli", me->query("max_jingli")*(10+random(5))/10);
	ob->set("jingli", ob->query("max_jingli"));

	i = random(9);
	switch (i) {
	case 0 :
		room_no=1+random(10);
		break;
	case 1 :
		room_no=11+random(10);
		break;
	case 2 :
		room_no=21+random(10);
		break;
	case 3 :
		room_no=31+random(10);
		break;
	case 4 :
		room_no=41+random(10);
		break;
	case 5 :
		room_no=51+random(10);
		break;
	case 6 :
		room_no=61+random(10);
		break;
	case 7 :
		room_no=71+random(10);
		break;
	case 8 :
		room_no=81+random(14);
		break;
	}
	room=load_object("/d/dali/minov"+room_no+".c");
	remove_call_out("moveto");
	call_out("moveto", 15+random(8), ob, room_no);

	set_temp("job_offered",1);
	remove_call_out("clearn_jo");
	call_out("clean_jo", 60, who);

	me->set("dali/lastjob", me->query("mud_age"));

	if (room->query("short")==room->query("area"))
	{
		command("say ��"+room->query("area")+"����һ���ݱ���"+ob->query("name")+"���");
	}
	else {
		switch (random(3))
		{
			case 0 :
				command("say "+room->query("area")+"����"+room->query("short")+"�зǷ�֮ͽ�춯��");
				break;
			case 1 :
				command("say ��"+room->query("area")+"����һ���ݱ���"+ob->query("name")+"���");
				break;
			case 2 :
				command("say �ݱ���"+ob->query("name")+"��"+room->query("area")+"�������");
				break;
		}
	}
	return "��ȥ��һ��Ѳ��Ѳ�飬���������ӵ�ͨ��Ҫ���ģ���ػ�׽�Ͷ�������";
}

void moveto(object ob, int room_no)
{
	object room;
	room_no=room_no+random(5)-random(5);
	if (room_no > 94) room_no=94;
	if (room_no < 1) room_no=1;
	room=load_object("/d/dali/minov"+room_no+".c");
	ob->move(room);

	switch (random(3)) {
	case 0 :
		message("vision", "һ��"+ob->query("name")+"��֪��ʲô�ط������������˳�����\n", room, ob);
		break;
	case 1 :
		message("vision", "һ��"+ob->query("name")+"��ҡ��ڵ����˹�����\n", room, ob);
		break;
	case 2 :
		message("vision", "һ��"+ob->query("name")+"ɱ�����ڵش�ɽ�ϳ�������\n", room, ob);
		break;
	}
	return;
}

void clean_jo(object ob)
{
	ob->delete_temp("job_offered");
	return;
}

void skill_set1(object ob, int level)
{
	object weapon;
	switch (ob->query("title")) {
	case "������������" :
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("staff", level-35+random(35));
		ob->set_skill("poison", level-35+random(35));
		ob->set_skill("huagong-dafa", level-35+random(35));
		ob->set_skill("zhaixinggong", level-35+random(35));
		ob->set_skill("tianshan-zhang", level-35+random(35));
		ob->map_skill("staff","tianshan-zhang");
		ob->map_skill("dodge","zhaixinggong");
		ob->map_skill("parry", "tianshan-zhang");
		ob->map_skill("force","huagong-dafa");
		ob->set_skill("claw", level-35+random(35));
		ob->set_skill("sanyin-zhua", level-35+random(35));
		ob->set_skill("strike", level-35+random(35));
		ob->set_skill("chousui-zhang", level-35+random(35));
		map_skill("claw","sanyin-zhua");
		map_skill("strike","chousui-zhang");
		prepare_skill("claw","sanyin-zhua");
		prepare_skill("strike","chousui-zhang");
		weapon=new("/d/xingxiu/obj/gangzhang.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "��ɽ����ͽ" :
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("zixia-gong", level-35+random(35));
		ob->set_skill("huashan-shenfa", level-35+random(35));
		ob->map_skill("dodge","huashan-shenfa");
		ob->map_skill("force","zixia-gong");
		ob->set_skill("cuff", level-35+random(35));
		ob->set_skill("pishi-poyu", level-35+random(35));
		ob->set_skill("strike", level-35+random(35));
		ob->set_skill("hunyuan-zhang", level-35+random(35));
		ob->map_skill("cuff","pishi-poyu");
		ob->map_skill("strike","hunyuan-zhang");
		ob->prepare_skill("cuff","pishi-poyu");
		ob->prepare_skill("strike","hunyuan-zhang");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-35+random(35));
			ob->set_skill("liangyi-dao", level-35+random(35));
			ob->map_skill("blade","liangyi-dao");
			ob->map_skill("parry","liangyi-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(35));
			ob->set_skill("huashan-jianfa", level-35+random(35));
			ob->map_skill("sword","huashan-jianfa");
			ob->map_skill("parry","huashan-jianfa");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "�䵱����ͽ" :
		ob->set_skill("cuff", level-35+random(35));
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("sword", level-35+random(35));
		ob->set_skill("taiji-shengong", level-35+random(35));
		ob->set_skill("taiji-jian", level-35+random(35));
		ob->set_skill("taiji-quan", level-35+random(35));
		ob->set_skill("tiyunzong", level-35+random(35));
		ob->map_skill("cuff","taiji-quan");
		ob->map_skill("sword","taiji-jian");
		ob->map_skill("dodge","tiyunzong");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("force","taiji-shengong");
		ob->prepare_skill("cuff","taiji-quan");
		weapon=new("/d/city/obj/gangjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "ѩɽ��С����" :
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("longxiang-banruo", level-35+random(35));
		ob->map_skill("force","longxiang-banruo");
		switch (random(2)) {
		case 0 :
			ob->set_skill("shenkongxing", level-35+random(35));
			ob->map_skill("dodge","shenkongxing");
			break;
		case 1 :
			ob->set_skill("xueshitiao", level-35+random(35));
			ob->map_skill("dodge","xueshitiao");
			break;
		}
		ob->set_skill("cuff", level-35+random(35));
		ob->set_skill("yujiamu-quan", level-35+random(35));
		ob->set_skill("hand", level-35+random(35));
		ob->set_skill("dashou-yin", level-35+random(35));
		ob->map_skill("cuff","yujiamu-quan");
		ob->map_skill("hand","dashou-yin");
		ob->prepare_skill("cuff","yujiamu-quan");
		ob->prepare_skill("hand","dashou-yin");
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-35+random(35));
			ob->set_skill("xue-dao", level-35+random(35));
			ob->map_skill("blade","xue-dao");
			ob->map_skill("parry","xue-dao");
			weapon=new("/d/xueshan/obj/miandao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(35));
			ob->set_skill("mingwang-jian", level-35+random(35));
			ob->map_skill("sword","mingwang-jian");
			ob->map_skill("parry","mingwang-jian");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("staff", level-35+random(35));
			ob->set_skill("jingang-chu", level-35+random(35));
			ob->map_skill("staff","jingang-chu");
			ob->map_skill("parry","jingang-chu");
			weapon=new("/d/xueshan/obj/fachu.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "ؤ�����" :
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("strike", level-35+random(35));
		ob->set_skill("huntian-qigong", level-35+random(35));
		ob->set_skill("xiaoyaoyou", level-35+random(35));
		ob->set_skill("xianglong-zhang", level-35+random(35));
		ob->map_skill("dodge","xiaoyaoyou");
		ob->map_skill("force","huntian-qigong");
		ob->map_skill("strike","xianglong-zhang");
		ob->prepare_skill("strike","xianglong-zhang");
		ob->set_skill("stick", level-35+random(35));
		ob->set_skill("dagou-bang", level-35+random(35));
		ob->map_skill("stick","dagou-bang");
		ob->map_skill("parry","dagou-bang");
		weapon=new("/d/city/obj/zhubang.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "�嶾�̴���" :
		ob->set_skill("cuff", level-35+random(35));
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("hook", level-35+random(35));
		ob->set_skill("ruyi-gou", level-35+random(35));
		ob->set_skill("wuxing-quan", level-35+random(35));
		ob->set_skill("wuxingbu", level-35+random(35));
		ob->map_skill("cuff","wuxing-quan");
		ob->map_skill("hook","ruyi-gou");
		ob->map_skill("dodge","wuxingbu");
		ob->map_skill("parry", "ruyi-gou");
		ob->prepare_skill("cuff","wuxing-quan");
		weapon=new("/clone/weapon/hook.c");
		weapon->move(ob);
		weapon->wield();
		break;
	}
	return;
}

void skill_set2(object ob, int level)
{
	object weapon;
	switch (ob->query("title")) {
	case "�������ֶ�ɮ" :
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("hunyuan-yiqi", level-35+random(35));
		ob->set_skill("shaolin-shenfa", level-35+random(35));
		ob->map_skill("dodge","shaolin-shenfa");
		ob->map_skill("force","hunyuan-yiqi");
		switch (random(3)) {
		case 0 :
			ob->set_skill("finger", level-35+random(35));
			ob->set_skill("yizhi-chan", level-35+random(35));
			ob->set_skill("strike", level-35+random(35));
			ob->set_skill("banruo-zhang", level-35+random(35));
			ob->map_skill("finger","yizhi-chan");
			ob->map_skill("strike","banruo-zhang");
			ob->prepare_skill("finger","yizhi-chan");
			ob->prepare_skill("strike","banruo-zhang");
			break;
		case 1 :
			ob->set_skill("cuff", level-35+random(35));
			ob->set_skill("jingang-quan", level-35+random(35));
			ob->map_skill("cuff","jingang-quan");
			ob->prepare_skill("cuff","jingang-quan");
			break;
		case 2 :
			ob->set_skill("finger", level-35+random(35));
			ob->set_skill("nianhua-zhi", level-35+random(35));
			ob->set_skill("strike", level-35+random(35));
			ob->set_skill("sanhua-zhang", level-35+random(35));
			ob->map_skill("finger","nianhua-zhi");
			ob->map_skill("strike","sanhua-zhang");
			ob->prepare_skill("finger","nianhua-zhi");
			ob->prepare_skill("strike","sanhua-zhang");
			break;
		}
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-35+random(35));
			ob->set_skill("xiuluo-dao", level-35+random(35));
			ob->map_skill("blade","xiuluo-dao");
			ob->map_skill("parry","xiuluo-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(35));
			ob->set_skill("fumo-jian", level-35+random(35));
			ob->map_skill("sword","fumo-jian");
			ob->map_skill("parry","fumo-jian");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("club", level-35+random(35));
			ob->set_skill("zui-gun", level-35+random(35));
			ob->map_skill("club","zui-gun");
			ob->map_skill("parry","zui-gun");
			weapon=new("/clone/weapon/qimeigun.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "��ɽ����ͽ" :
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("zixia-gong", level-35+random(35));
		ob->set_skill("huashan-shenfa", level-35+random(35));
		ob->map_skill("dodge","huashan-shenfa");
		ob->map_skill("force","zixia-gong");
		ob->set_skill("cuff", level-35+random(35));
		ob->set_skill("pishi-poyu", level-35+random(35));
		ob->set_skill("strike", level-35+random(35));
		ob->set_skill("hunyuan-zhang", level-35+random(35));
		ob->map_skill("cuff","pishi-poyu");
		ob->map_skill("strike","hunyuan-zhang");
		ob->prepare_skill("cuff","pishi-poyu");
		ob->prepare_skill("strike","hunyuan-zhang");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-35+random(35));
			ob->set_skill("liangyi-dao", level-35+random(35));
			ob->map_skill("blade","liangyi-dao");
			ob->map_skill("parry","liangyi-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(35));
			ob->set_skill("huashan-jianfa", level-35+random(35));
			ob->map_skill("sword","huashan-jianfa");
			ob->map_skill("parry","huashan-jianfa");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "�䵱����ͽ" :
		ob->set_skill("cuff", level-35+random(35));
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("sword", level-35+random(35));
		ob->set_skill("taiji-shengong", level-35+random(35));
		ob->set_skill("taiji-jian", level-35+random(35));
		ob->set_skill("taiji-quan", level-35+random(35));
		ob->set_skill("tiyunzong", level-35+random(35));
		ob->map_skill("cuff","taiji-quan");
		ob->map_skill("sword","taiji-jian");
		ob->map_skill("dodge","tiyunzong");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("force","taiji-shengong");
		ob->prepare_skill("cuff","taiji-quan");
		weapon=new("/d/city/obj/gangjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "ѩɽ������" :
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("longxiang-banruo", level-35+random(35));
		ob->map_skill("force","longxiang-banruo");
		switch (random(2)) {
		case 0 :
			ob->set_skill("shenkongxing", level-35+random(35));
			ob->map_skill("dodge","shenkongxing");
			break;
			case 1 :
			ob->set_skill("xueshitiao", level-35+random(35));
			ob->map_skill("dodge","xueshitiao");
			break;
		}
		ob->set_skill("cuff", level-35+random(35));
		ob->set_skill("yujiamu-quan", level-35+random(35));
		ob->set_skill("hand", level-35+random(35));
		ob->set_skill("dashou-yin", level-35+random(35));
		ob->map_skill("cuff","yujiamu-quan");
		ob->map_skill("hand","dashou-yin");
		ob->prepare_skill("cuff","yujiamu-quan");
		ob->prepare_skill("hand","dashou-yin");
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-35+random(35));
			ob->set_skill("xue-dao", level-35+random(35));
			ob->map_skill("blade","xue-dao");
			ob->map_skill("parry","xue-dao");
			weapon=new("/d/xueshan/obj/miandao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(35));
			ob->set_skill("mingwang-jian", level-35+random(35));
			ob->map_skill("sword","mingwang-jian");
			ob->map_skill("parry","mingwang-jian");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("staff", level-35+random(35));
			ob->set_skill("jingang-chu", level-35+random(35));
			ob->map_skill("staff","jingang-chu");
			ob->map_skill("parry","jingang-chu");
			weapon=new("/d/xueshan/obj/fachu.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "�嶾������" :
		ob->set_skill("cuff", level-35+random(35));
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("hook", level-35+random(35));
		ob->set_skill("ruyi-gou", level-35+random(35));
		ob->set_skill("wuxing-quan", level-35+random(35));
		ob->set_skill("wuxingbu", level-35+random(35));
		ob->map_skill("cuff","wuxing-quan");
		ob->map_skill("hook","ruyi-gou");
		ob->map_skill("dodge","wuxingbu");
		ob->map_skill("parry", "ruyi-gou");
		ob->prepare_skill("cuff","wuxing-quan");
		weapon=new("/clone/weapon/hook.c");
		weapon->move(ob);
		weapon->wield();
		break;
	}
	return;
}

void skill_set3(object ob, int level)
{
	object weapon;
	switch (ob->query("title")) {
	case "�������ָ�ɮ" :
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("hunyuan-yiqi", level-35+random(35));
		ob->set_skill("shaolin-shenfa", level-35+random(35));
		ob->map_skill("dodge","shaolin-shenfa");
		ob->map_skill("force","hunyuan-yiqi");
		switch (random(3)) {
		case 0 :
			ob->set_skill("finger", level-35+random(35));
			ob->set_skill("yizhi-chan", level-35+random(35));
			ob->set_skill("strike", level-35+random(35));
			ob->set_skill("banruo-zhang", level-35+random(35));
			ob->map_skill("finger","yizhi-chan");
			ob->map_skill("strike","banruo-zhang");
			ob->prepare_skill("finger","yizhi-chan");
			ob->prepare_skill("strike","banruo-zhang");
			break;
		case 1 :
			ob->set_skill("cuff", level-35+random(35));
			ob->set_skill("jingang-quan", level-35+random(35));
			ob->map_skill("cuff","jingang-quan");
			ob->prepare_skill("cuff","jingang-quan");
			break;
		case 2 :
			ob->set_skill("finger", level-35+random(35));
			ob->set_skill("nianhua-zhi", level-35+random(35));
			ob->set_skill("strike", level-35+random(35));
			ob->set_skill("sanhua-zhang", level-35+random(35));
			ob->map_skill("finger","nianhua-zhi");
			ob->map_skill("strike","sanhua-zhang");
			ob->prepare_skill("finger","nianhua-zhi");
			ob->prepare_skill("strike","sanhua-zhang");
			break;
		}
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-35+random(35));
			ob->set_skill("cibei-dao", level-35+random(35));
			ob->map_skill("blade","cibei-dao");
			ob->map_skill("parry","cibei-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("whip", level-35+random(35));
			ob->set_skill("riyue-bian", level-35+random(35));
			ob->map_skill("whip","riyue-bian");
			ob->map_skill("parry","riyue-bian");
			weapon=new("/clone/weapon/changbian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("club", level-35+random(35));
			ob->set_skill("zui-gun", level-35+random(35));
			ob->map_skill("club","zui-gun");
			ob->map_skill("parry","zui-gun");
			weapon=new("/clone/weapon/qimeigun.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "��ɽ����ͽ" :
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("zixia-gong", level-35+random(35));
		ob->set_skill("huashan-shenfa", level-35+random(35));
		ob->map_skill("dodge","huashan-shenfa");
		ob->map_skill("force","zixia-gong");
		ob->set_skill("cuff", level-35+random(35));
		ob->set_skill("pishi-poyu", level-35+random(35));
		ob->set_skill("strike", level-35+random(35));
		ob->set_skill("hunyuan-zhang", level-35+random(35));
		ob->map_skill("cuff","pishi-poyu");
		ob->map_skill("strike","hunyuan-zhang");
		ob->prepare_skill("cuff","pishi-poyu");
		ob->prepare_skill("strike","hunyuan-zhang");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-35+random(35));
			ob->set_skill("liangyi-dao", level-35+random(35));
			ob->map_skill("blade","liangyi-dao");
			ob->map_skill("parry","liangyi-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(35));
			ob->set_skill("huashan-jianfa", level-35+random(35));
			ob->map_skill("sword","huashan-jianfa");
			ob->map_skill("parry","huashan-jianfa");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "�䵱����ͽ" :
		ob->set_skill("cuff", level-35+random(35));
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level-35+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("sword", level-35+random(35));
		ob->set_skill("taiji-shengong", level-35+random(35));
		ob->set_skill("taiji-jian", level-35+random(35));
		ob->set_skill("taiji-quan", level-35+random(35));
		ob->set_skill("tiyunzong", level-35+random(35));
		ob->map_skill("cuff","taiji-quan");
		ob->map_skill("sword","taiji-jian");
		ob->map_skill("dodge","tiyunzong");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("force","taiji-shengong");
		ob->prepare_skill("cuff","taiji-quan");
		weapon=new("/d/city/obj/gangjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "ѩɽ������" :
		ob->set_skill("dodge", level-40+random(5));
		ob->set_skill("force", level-40+random(5));
		ob->set_skill("parry", level-40+random(5));
		ob->set_skill("longxiang-banruo", level-35+random(5));
		ob->map_skill("force","longxiang-banruo");
		switch (random(2)) {
		case 0 :
			ob->set_skill("shenkongxing", level-40+random(5));
			ob->map_skill("dodge","shenkongxing");
			break;
			case 1 :
			ob->set_skill("xueshitiao", level-40+random(5));
			ob->map_skill("dodge","xueshitiao");
			break;
		}
		ob->set_skill("strike", level-35+random(35));
		ob->set_skill("huoyan-dao", level-35+random(35));
		ob->map_skill("strike","huoyan-dao");
		ob->prepare_skill("strike","huoyan-dao");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-35+random(35));
			ob->set_skill("xue-dao", level-35+random(35));
			ob->map_skill("blade","xue-dao");
			ob->map_skill("parry","xue-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("hammer", level-40+random(5));
			ob->set_skill("riyue-lun", level-40+random(35));
			ob->map_skill("hammer","riyue-lun");
			ob->map_skill("parry","riyue-lun");
			weapon=new("/clone/weapon/falun.c");
			weapon->set_amount(3);
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "�嶾������" :
		ob->set_skill("cuff", level-35+random(35));
		ob->set_skill("dodge", level-35+random(35));
		ob->set_skill("force", level+random(35));
		ob->set_skill("parry", level-35+random(35));
		ob->set_skill("hook", level-35+random(35));
		ob->set_skill("ruyi-gou", level-35+random(35));
		ob->set_skill("wuxing-quan", level-35+random(35));
		ob->set_skill("wuxingbu", level-35+random(35));
		ob->map_skill("cuff","wuxing-quan");
		ob->map_skill("hook","ruyi-gou");
		ob->map_skill("dodge","wuxingbu");
		ob->map_skill("parry", "ruyi-gou");
		ob->prepare_skill("cuff","wuxing-quan");
		weapon=new("/clone/weapon/hook.c");
		weapon->move(ob);
		weapon->wield();
		break;
	}
	return;
}

#include "/kungfu/class/dali/sangong.h"
