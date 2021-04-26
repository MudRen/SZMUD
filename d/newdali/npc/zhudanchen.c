// Code of ShenZhou
// zhudanchen.c

inherit NPC;
inherit F_MASTER;

string ask_xialuo();
string ask_tan();
string ask_path();

void create()
{
	set_name("�쵤��", ({ "zhu danchen", "zhu"}));
	set("long", "������һ��ʫ�飬���������ж������ϲ���һ���йٱʡ�\n");
	set("title","������佫");
	set("gender", "����");
	set("age", 35);
	set("inquiry", ([
		"������": "�Ҽ���ү���Է�����",
		"����"  : "�Ҽ�С��������ܶ��ˣ���ôҲ�Ҳ�����������������֪���Ҽ����ӵ����䣬������档",
		"����"  : (: ask_xialuo :),
		"����̶": (: ask_tan :),
		"����"  : (: ask_path :),
        ]));
	set_skill("strike", 60);
	set_skill("qingyan-zhang", 60);
	set_skill("dodge", 60);
	set_skill("duanshi-shenfa", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("buddhism", 80);
	set_skill("sword", 60);
	set_skill("kurong-changong",60);
	set_skill("duanjia-jian", 60);
	map_skill("cuff","jinyu-quan");
	map_skill("dodge","duanshi-shenfa");
	map_skill("sword","duanjia-jian");
	map_skill("force","kurong-changong");
	map_skill("parry","duanjia-jian");
	prepare_skill("strike","qingyan-zhang");

	set("str", 28);
	set("int", 29);
	set("con", 27);
	set("dex", 23);
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 550);
	set("max_neili", 550);
	set("jiali", 50);
	set("combat_exp", 150000);
	set("chat_chance", 5);
	set("chat_msg", ({
"�쵤������˵���������ӳ����鷿���׾�����ϧ�Ҳ��ܶ����Ű���֮������\n",
"�쵤����ָ������ʲô�������������������֮���������������ɵ���·����ǧ֮����ȥ�����ɵ��������� ...��\n",
"�쵤�����е�ɫ�����������... �ں����У����������򱶣��������ȡ�������ɡ���\n",
	}) );

	set("attitude", "peaceful");
	set("shen_type", 1);
	create_family("����μ�", 15, "����");
	setup();
	carry_object("/d/dali/obj/ycloth")->wear();	
	carry_object("/d/dali/obj/panguanbi")->wield();
}

void attempt_apprentice(object ob)
{
	mapping fam;
	string dldj;

        command ("look "+ob->query("id"));
        if ( ob->query("class")=="bonze" ) {
             if (ob->query("gender")=="Ů��")
                command ("say ʦ̫�Ƕ����ɵĸ��֣������Ƨ֮�粻�Ҷ�����");
             else
                command ("say ��ʦ�������ɵĸ��֣������Ƨ֮�粻�Ҷ�����");
             return;
        }
        if( ob->query("family/family_name") == "ؤ��") {
                command ("say �������ǻ���֮�أ����ʼ�������ؤ�ɺ���ͳ��");
                return;
        }
        if ( ob->query("family/family_name") == "�䵱��" && 
ob->query("combat_exp") >= 10000 ) {
                command ("say ����֮�����з�̣���λ���ֻ�����������ɡ�");
                return;
        }

       if ( ob->query("family/family_name") == "������" && 
ob->query("combat_exp") >= 10000 ) {
                command ("say �������޶���Ҳ�����Ҵ����ڳ���������ȥ!");
                return;
        }
      if ( ob->query("family/family_name") == "����ɽ" && 
ob->query("combat_exp") >= 10000 ) {
                command ("say ������ն���Ҳ�����Ҵ����ڳ���������ȥ!");
                return;
        }
       if ( ob->query("family/family_name") == "��ɽ��" && 
ob->query("combat_exp") >= 10000 ) {
                command ("say ����֮�����з�̣���λ���ֻ�����������ɡ�");
                return;
        }
if ( ob->query("family/family_name") == "Ѫ����" && ob->query("combat_exp") 
>= 10000 ) {
                command ("say 
����Ѫ���ŵĶ���Ҳ�����Ҵ����ڳ���������ȥ!");
                return;
        }
if ( ob->query("family/family_name") == "������" && ob->query("combat_exp") 
>= 10000 ) {
                command ("say
���������̵Ķ���Ҳ�����Ҵ����ڳ���������ȥ!");
                return;
        }

        if (ob->query("shen") <0) { command ("say �������ݲ������������С��!");
                return;
        }
        


        if (ob->query("gender")=="Ů��") dldj="�Ů";
        else  dldj = "�Ҷ�";
        command("say �ðɣ��ҾͶ�������ү����������" + dldj + "�ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title","�����ƽ������"+dldj);
        return;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "�쵤��Ц�����˵������λ" + 
RANK_D->query_respect(ob)
                                + "����ӭ��������\n");
                        break;
                case 1:
                        say( "�쵤������˵������λ" + 
RANK_D->query_respect(ob)
                                + 
"�����ʿ��п���һλ��ʮ�����µ����๫�ӡ�\n");
                        break;
        }
}

string ask_xialuo()
{
	object me;
	me=this_player();

	if (!me->query_temp("mazepath") && !me->query_temp("ydquest/query1")) {
		me->set_temp("ydquest/query1",1);
		return "���ӳ��ߺü����ˣ�һ����ϢҲû�С�... ... \n�Ҹո���˵�����Ϻ���̶��λ�����ϸ�������֪����ʲô����ȥ����������\n";
	}
	else return "���... �Ҳ�̫������㻹�����ʱ��˰ɡ�";
}

string ask_tan()
{
	object me;
	me=this_player();

	if (me->query_temp("ydquest/query1") && !me->query_temp("ydquest/query2")) {
		me->delete_temp("ydquest/query1");
		me->set_temp("ydquest/query2",1);
		return "����̶�������������ߣ����ǵش����ܣ�����һƬ����֮�У���Ƭ���е�·�������ǰ����Ű����˹����Ƶġ�\n";
	}
	return "�Բ������ʵ�����ʵ��û��ӡ��\n";
}

string ask_path()
{
	object me;
	int passwd,path;
	me=this_player();
	passwd=random(998)+2;
	path=passwd*(1000-passwd);
	if (path>99999) path=path/10;
	if (path<10000) path=path*10;
 
	if (me->query_temp("ydquest/query2")) {
		write("�쵤��������ϸ������һ�󡣷�������ߡ�\n");
		command("whisper "+getuid(me)+" �����ڵ�������"+CHINESE_D->chinese_number(passwd));
		me->set_temp("mazepath", path);
		me->delete_temp("ydquest/query2");
		return "�˸�������"+RANK_D->query_respect(me)+"��������������������������ˣ������Ϊ֮��\n";
	}
	return "�Բ������ʵ�����ʵ��û��ӡ��\n";
}
