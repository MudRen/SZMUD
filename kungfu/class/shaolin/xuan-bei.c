// Code of ShenZhou
// Npc: /kungfu/class/shaolin/xuan-bei.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("������ʦ", ({
		"xuanbei dashi",
		"xuanbei",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ���������ߣ�\n"
		"��������񣬶��Ÿ��ʣ�˫ĿտȻ����\n"
	);

	set("nickname", "��ĦԺ����");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1200000);
	set("score", 500000);

	set_skill("force", 150);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 150);
        set_skill("cuff", 120);
        set_skill("luohan-quan", 120);
        set_skill("club", 120);
        set_skill("weituo-gun", 120);
        set_skill("strike", 120);
        set_skill("sanhua-zhang", 120);
        set_skill("hand", 160);
        set_skill("qianye-shou", 160);
        set_skill("claw", 160);
        set_skill("yingzhua-gong", 160);
	set_skill("parry", 150);
	set_skill("buddhism", 150);
	set_skill("literate", 101);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("club", "weituo-gun");
        map_skill("strike", "sanhua-zhang");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "yingzhua-gong");
	map_skill("parry", "yingzhua-gong");

	prepare_skill("hand", "qianye-shou");
	prepare_skill("claw", "yingzhua-gong");

	create_family("������", 36, "����");

	set("inquiry", ([
		"������"       : (: ask_me :),
	]));

	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] < my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( (ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��") 
	||   (ob_fam["generation"] >=  my_fam["generation"]      && name[0..1] == "��") )
	{
		command("say " + ob_fam["master_name"] + "��ͽ����ô�ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}
	else
	{
		command("say " + RANK_D->query_respect(ob) + "���㱲�ݲ��ϣ�����Խ����ʦ��");
		return;
	}

	return;
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		command("nod " + ob->query("id"));
	}
}

string ask_me()
{
	mapping fam, skill; 
	object ob, mengzhu, room;
	string *sname, name;
	int i, ready;
	
	name = this_player()->query("name");

	if ( name[0..1] == "��" )
		return RANK_D->query_respect(this_player()) + 
		"�������ֱ����ӣ��ο�����Ŀ������Ц��";

	if ( this_object()->query_temp("calling") || this_player()->query_temp("calling"))
		return "���Ѿ�����ȥ����λ�����ˣ�" 
		+ RANK_D->query_respect(this_player()) + "�����ĵȺ�ʮ�죬���з�����";

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

        if ( (int)this_player()->query("guilty") > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���۷����䣬����������������ֱ����ҵ�ͬ�У�";

	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");
        seteuid(getuid(this_player()));
        if( !objectp(mengzhu = present("mengzhu", room)) )
        mengzhu = new("/clone/npc/meng-zhu");
        if (userp(this_player()) && this_player()->query("id") == mengzhu->query("winner") ){
        return "������Ϊ���������������ϾͲ��ؼ��ˣ�";
        }

	skill = this_player()->query_skills();
	sname  = keys(skill);

	for(i=0; i<sizeof(skill); i++) {
		if ( skill[sname[i]] < 100 ) 
		return RANK_D->query_respect(this_player()) + 
		"�Ļ�������δ�ﾫ��֮�����ҿ��в����ʸ������λ���ϡ�";
	}

	if ( skill["force"] < 120
	||   skill["hunyuan-yiqi"] < 120	    
	||   skill["dodge"] < 120	    
	||   skill["shaolin-shenfa"] < 120	    
	||   skill["parry"] < 120 )	    
		return RANK_D->query_respect(this_player()) + 
		"���ܰٳ߸�ͷ���ٽ�һ����ƾ�����Ϊ���ҵ�����λ���ϱ����������࣡";

        if ( (int)this_player()->query_skill("buddhism",1) < 120 )
		return RANK_D->query_respect(this_player()) + 
		"�ķ���Ϊδ���ˣ���Ȼ�޷������λ���ϵ��������ҿ����ǲ���Ϊ�á�";

	if( fam["master_name"] != this_object()->name() )
		command("say " + fam["master_name"] + "��ͽ����־���� ����������ͷ����û������ȥ�ˣ������� ��");
	else 	command("say ��ͽ������־���� ����������ͷ����û������ȥ�ˣ������� ��");

	message_vision("$N��������ߵ�Сɳ��˵�˼��仰��Сɳ�ֵ��ͷ�����˳�ȥ��\n",this_object());

	this_object()->set_temp("calling", 1);
	this_player()->set_temp("calling", 1);

	ob = present("xiao shami", environment(this_object()) );
	ob->move("/d/shaolin/qyping");

//	ready = 3600 + random(3600);
	ready = 100;
	
	call_out("calling", 1, 0, ready);
	call_out("leaving", 1, 0, ready + 900);

	return "�ðɣ�������֪����λ���ϣ������пվͻ���ɽ�����ߣ���ʱ���ڴ˵Ⱥ���ǡ�";

}

int calling(int time, int ready)
{
	object room, ob;
	
	if ( time < ready ) {
		time = time + 100;
		call_out("calling", 100, time, ready);
                return 1;
	}
	else {
                if(!( room = find_object("/d/shaolin/fumoquan")) )
                room = load_object("/d/shaolin/fumoquan");

		this_object()->delete_temp("calling");

		switch( random(3) ) {
		case 0:
			ob = present("du nan", room);
			ob->move("/d/shaolin/dmyuan2");
			break;
		case 1:
			ob = present("du jie", room);
			ob->move("/d/shaolin/dmyuan2");
			break;
		case 2:
			ob = present("du e", room);
			ob->move("/d/shaolin/dmyuan2");
			break;
		}
		return 1;
	}	
}

int leaving(int time, int ready)
{
	object room, ob;
	
	if ( time < ready ) {
		time = time + 100;
		call_out("calling", 100, time, ready);
                return 1;
	}
	else {
                if(!( room = find_object("/d/shaolin/dmyuan2")) );
                room = load_object("/d/shaolin/dmyuan2");

		if( objectp(ob = present("du nan", room)) 
		||  objectp(ob = present("du jie", room))
		||  objectp(ob = present("du e",   room)) ) 
		{
			message_vision( ob->name() + "���ͷ��˵�����˼������ˣ���ȥ�ˡ�\n" + 
					"��˵�մ���ƮƮ���ﳤ������ֻһ�����ʧ���ټ���\n", ob);
			ob->move("/d/shaolin/fumoquan");
		}

		return 1;
	}	
}
#include "/kungfu/class/shaolin/auto_perform.h"
