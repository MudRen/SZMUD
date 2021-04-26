// Code of ShenZhou
// fan-ye.c ����

#define BUSY_TIME 360
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
		"job" : (: ask_me :),
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
	
	if ( time() < me->query("mp_job_time") + BUSY_TIME ) 
                return "����������ûʲôҪ�������飬"+RANK_D->query_respect(me)+"���Ȼ�ȥ��Ϣ�ɡ�";	
        
        if (!me->query("dali/employee") && me->query("combat_exp")>800000 )
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
	ob->set("shen",-ob->query("combat_exp")/10);
	ob->set("max_qi", me->query("max_qi")*(12+random(5))/10);
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("max_jing", me->query("max_jing")*(10+random(3))/10);
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	ob->set("max_neili", me->query("max_neili")*(10+random(4))/10);
	ob->set("neili", ob->query("max_neili"));
	ob->set("jiali",ob->query("max_neili")/50);
	ob->set("max_jingli", me->query("max_jingli")*(10+random(4))/10);
	ob->set("jingli", ob->query("max_jingli"));
        ob->set("owner", me->query("id")); 

	i = random(6)+1;
	switch (i) {
	case 1 :
		areaname="��٤��";
		room_no=12+random(8);
		break;
	case 2 :
		areaname="������";
		room_no=21+random(8);
		break;
	case 3 :
		areaname="���۲�";
		room_no=31+random(7);
		break;
	case 4 :
		areaname="����ˮ�ȵ�";
		room_no=41+random(17);
		break;
	case 5 :
		areaname="ϲ�ݳ���";
		room_no=64+random(16);
		break;
	case 6 :
		areaname="��������";
		room_no=81+random(9);
		break;
	}
	room=load_object("/d/dali/minov"+room_no+".c");
	remove_call_out("moveto");
	call_out("moveto", 15+random(8), ob, room_no);

	set_temp("job_offered",1);
	remove_call_out("clearn_jo");
	call_out("clean_jo", 50, who);

	me->set("dali/lastjob", me->query("mud_age"));
	me->set_temp( "daliob", ob );

	command("say "+areaname+"һ����"+room->query("short")+"�ݱ���"+ob->query("name")+"���");
	return "��ȥ��һ��Ѳ��Ѳ�飬���������ӵ�ͨ��Ҫ���ģ���ػ�׽�Ͷ�������";
}

void moveto(object ob, int room_no)
{
	object room;
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

#include "/kungfu/class/dali/sangong.h"
#include "/d/dali/npc/fy-skset1.h"
