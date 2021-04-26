// Code of ShenZhou
// zhanggui.c

inherit NPC;
inherit F_DEALER;

int ask_me(string);
int ask_yaofang();

void create()
{
	set_name("��ͨ��", ({ "wang tongzhi", "wang"}));
	set("title","ҩ���ƹ�");
	set("gender", "����" );
	set("age", 62);
	set("long",
		"����λ��Ŀ���Ƶ����ˣ��ݳ�ҽ��������ȥ��\n");
	set("combat_exp", 20000);
	set("shen_type", 1);
	set("str", 12);
	set("int", 25);
	set("con", 23);
	set("dex", 20);
	set("max_qi", 800);
	set("max_jing", 800);
	set("max_neili", 800);
	set_skill("ding-force", 80);
	set_skill("force", 80);
	map_skill("force", "ding-force");

	set("attitude", "friendly");
	set("rank_info/respect", "���ϰ�");

	set("vendor_goods", ({
		HERB_D("badou"),
		HERB_D("baotai"),
		HERB_D("chantui"),
		HERB_D("chuanbei"),
		HERB_D("chuanshanjia"),
		HERB_D("fangfeng"),
		HERB_D("fuling"),
		HERB_D("gouzhizi"),
		HERB_D("heshouwu"),
		HERB_D("heye"),
		HERB_D("huanglian"),
		HERB_D("jugeng"),
		HERB_D("jy-hua"),
		HERB_D("niuhuang"),
		HERB_D("renshen"),
		HERB_D("shadan"),
		HERB_D("shengdi"),
		HERB_D("tianqi"),
		HERB_D("xiongdan"),
		HERB_D("xionghuang"),
		HERB_D("xuelianzi"),
		HERB_D("zhh-hua"),
		HERB_D("kuihua"),
                HERB_D("yaochu2"),
	}));

    set("inquiry", ([
		"ҩ��" : (: ask_yaofang :),
        "��ҩ" : (: ask_me, "jc-yao" :),
        "������" : (: ask_me, "yx-wan" :),
        "������" : (: ask_me, "yj-dan" :),
        "����ɢ" : (: ask_me, "qx-san" :),
        "��ҩ"   : (: ask_me, "she-yao" :),
        "�ٲݵ�" : (: ask_me, "bc-dan" :),
        "�Ż���¶��" : (: ask_me, "none" :),
        "�����赨ɢ" : (: ask_me, "none" :),
        "�����˵�" : (: ask_me, "none" :),
        "��ʯ�񶴵�" : (: ask_me, "none" :),
        "����ɢ" : (: ask_me, "none" :),
        "������" : (: ask_me, "none" :),
        "���Ʊ�����" : (: ask_me, "none" :),
        "ͨϬ������" : (: ask_me, "none" :),
        "�����ܵ���" : (: ask_me, "none" :),
        ]) );
	setup();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			command(query("name")+"Ц�����˵������λ" + 
RANK_D->query_respect(ob)+ "����Ҫ��ʲôҩ��\n");
			break;
		case 1:
			say( query("name")+"Ц����ع��˹��֣�˵������λ" + 
RANK_D->query_respect(ob)+ "����������\n");
			break;
	}
}

int ask_yaofang()
{
	object me = this_player();
    if (!me->query_temp("zg_mark"))
    {
	command("say ���಻�ţ�ҽ��ƽƽ��������ʲôҩ����\n");
	    return 1;
    }
	command("say "+RANK_D->query_respect(me)+"Ҫ��ʲôҩ�ķ��ӣ�����˵�ɡ�\n");
	return 1;
}

int ask_me(string name)
{
	object me = this_player();
	string myid;
	myid = me->query("id");

        if (!me->query_temp("zg_mark"))
        {
        	
command("say "+RANK_D->query_respect(me)+"Ҫ��ʲôҩ����˵��������ҩ�������\n");
			return 1;
		}
		
        if ( name == "none" ) 
		{
			command("doubt "+query("id"));
			command ("say �����������������ҿ�ʵ�ڲ�֪���ˡ�\n");
			return 1;
		}
		
		
		if (name == "jc-yao")
		{
			switch (random(5))
			{
				case 0:
	                command("whisper " + myid + " " + "������Ǯ������һǮ����ˮ�尾�Ϳ��Ƴ�һ����ҩ��");
					break;
				case 1:
	                command("whisper " + myid + " " + "�������İ����������һǮ����ˮ�尾�Ϳ��Ƴ�һ����ҩ��");
					break;
				case 2:
	                command("whisper " + myid + " " + "����������������һǮ���������һǮ����ˮ�尾�Ϳ��Ƴ�һ����ҩ��");
					break;
				case 3:
	                command("whisper " + myid + " " + "������Ǯ�ӷ�����Ǯ����ˮ�尾�Ϳ��Ƴ�һ����ҩ��");
					break;
				case 4:
	                command("whisper " + myid + " " + "��������������һǮ���ټӷ���һǮ����ˮ�尾�Ϳ��Ƴ�һ����ҩ��");
					break;
			}
		}
		
        if (name == "yx-wan")
        {
	    	command("whisper " + myid + " " + "����һǮ��������һ�����չ�һǮ����ˮ�尾�Ϳ��Ƴɡ�");
		}
        
        if (name == "yj-dan")
        {
	    	command("whisper " + myid + " " + "��Ҷһ�ţ��չ�һǮ����ˮ���ɾͿ��Ƴɡ�");
		}
        	
        if (name == "qx-san")
        {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "�ۻ�һǮ���԰Ͷ�Ϊ��к������ˮ���ɾͿ��Ƴɡ�");
					break;
				case 1:
	                command("whisper " + myid + " " + "�չ���Ǯ���԰Ͷ�Ϊ��к������ˮ���ɾͿ��Ƴɡ�");
					break;
			}
		}
        
        if (name == "she-yao")
        {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "ţ��һǮ���ۻ�һǮ����ˮ���ɾͿ��Ƴɡ�");
					break;
				case 1:
	                command("whisper " + myid + " " + "ţ��һǮ���չ���Ǯ����ˮ���ɾͿ��Ƴɡ�");
					break;
			}
		}
 
        if (name == "bc-dan")
       {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "�غ컨һǮ��������Ǯ����ˮ���ɾͿ��Ƴɡ�");
					break;
				case 1:
	                command("whisper " + myid + " " + "�غ컨һǮ����ɽ��һֻ����ˮ�������ͼ��ɡ�");
					break;
			}
		}
 	me->delete_temp("zg_mark");
 	return 1;
 }

int accept_object(object who, object ob)
{
	int i;
	if ( ob->query("money_id") )
    {
    	if ( ob->value() >= 10000 )
        {
			
command 
("say �ȳ�"+RANK_D->query_respect(who)+"�ؽ�֮�ݣ��к����ʾ���˵��������֪�޲��ԣ����޲�����\n");
           	who->set_temp("zg_mark",1);
			return 1;
		}

		command(":)");
		return 1;
	}

	return 0;
}		

