//Cracked by Roath
// Jay 10/7/96

inherit NPC;
inherit F_MASTER;
string ask_me();
//string ask_camel();

void create()
{
        set_name("������", ({ "yin kexi","yin","kexi" }));
        set("long", "�������Ǹ���˹���ˣ��߱���Ŀ����ǰ�Ǹ��鱦�̣���Ϊ��ͨ���ʣ���ŷ�������������˷�������\n");
        set("gender", "����");
	    set("title","����ɽׯ�˷�����");
        set("age", 35);

        set_skill("cuff", 50);
	    set_skill("lingshe-quan", 50);
        set_skill("dodge", 60);
	    set_skill("chanchubu", 60);
        set_skill("parry", 50);
        set_skill("force", 50);
	    set_skill("hamagong", 50);
	    set_skill("strike",50);
	    set_skill("poison",40);
	    set_skill("training",50);
	    map_skill("cuff","lingshe-quan");
        map_skill("dodge","chanchubu");
	    map_skill("force","hamagong");
	    prepare_skill("cuff","lingshe-quan");

        set("str", 28);
        set("int", 21);
        set("con", 27);
        set("dex", 21);

        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 550);
        set("max_neili", 550);
        set("jiali", 40);
        set("combat_exp", 100000);

        set("attitude", "peaceful");
        set("shen_type", -1);
        set("inquiry", ([
			"��Ǯ" : (: ask_me :),	
			"pay" : (: ask_me :),

	//	"����" : (: ask_camel :),
	//	"����" : (: ask_camel :),
        ]));

        create_family("����ɽ", 3 , "����");
	setup();
	carry_object("/clone/armor/changpao")->wear();
	add_money("gold",2);
}
/*void init()
{
        add_action("return_camel", "��");
        add_action("return_camel", "return");
}

int return_camel(string arg)
{
    object ob, me = this_player();

    if( !arg || arg=="" ) return 0;

    if (!ob=present("camel", environment(me)))  return 0;

    if (ob->query_lord() != me) return 0;


    if( arg=="camel" ) {
        message_vision("$N���������յ�����������$n��\n", me, this_object());
        add("camel_count", -1);

        if(me->query("rided"))
        me->set("rided", 0);

        destruct(ob);
	return 1;
	}
}
*/
void attempt_apprentice(object ob)
{
        mapping fam;
	string ttt;

	command ("look "+ob->query("id"));
	if ( ob->query("class")=="bonze" ) {
             if (ob->query("gender")=="Ů��")
		command ("say Сʦ̫����󡹦�����±��˽���ͺͷ�����");
	     else
		command ("say ��ʦ������󡹦�����±��˽���ͺͷ�����");
	     return;
	}
        if( ob->query("family/family_name") == "ؤ��") {
		command ("say ׯ��ƽ����޽л��ӣ��ҿɲ������㡣");
		return;
	}
        if ( ob->query("family/family_name") == "�䵱��") {
		command ("say �ϵ�����󡹦�����±��˽���ţ���Ӹ����");
		return;
	}

	if (ob->query("combat_exp") > 30000) {
		command ("say "+ RANK_D->query_respect(ob) + 
                           "�����ָ��֣�����Ϊʦ����ȡЦ�������ˡ�");
		return;
	}
	if (ob->query("int") <25) {
                command ("say "+ RANK_D->query_respect(ob) + 
                           "���Ժ�ֱ���������ʷ�����µġ�");
                return;
        }


	if (ob->query("gender")=="Ů��") ttt="�Ů";
	else  ttt = "�Ҷ�";
	command("say �ðɣ��������ɽׯ����" + ttt + "�ɡ�");
        command("recruit " + ob->query("id"));
	ob->set("title","����ɽׯ"+ttt);
	return;
}

string ask_me()
{
	object wage;
	object ob = this_player();
	if (ob->query("family/family_name")!="����ɽ") {
		command("say ������������" + RANK_D->query_rude(ob) +
			"������ׯ����ʳ������ҹ���");
		command("kick " + ob->query("id"));
		return ("С���������㣡");
	}
	if (ob->query("family/generation")<3) 
		return ("��ׯ����Ӧ�������С���ҷ���Ǯѽ��");
	if (!ob->query("combat_exp")) return ("�ȸɵ�ʲô����Ǯ��");
	if (ob->query("family/generation")>3) {
	if (ob->query("bt_exp") < ob->query("combat_exp") - 99) {
		wage = new("/clone/money/silver");
                wage->set_amount(1);
                wage->move(ob);
		ob->set("bt_exp",ob->query("combat_exp"));
		return("��������ӵĳ��ͣ��úøɣ�");
	}
	else return("���ϴ���нˮ���������Է����ɻ����û��Ĺ�Ǯ��");
	}
	if (ob->query("bt_exp") < ob->query("combat_exp") - 999) {
                wage = new("/clone/money/silver");
                wage->set_amount(10);
                wage->move(ob);
                ob->set("bt_exp",ob->query("combat_exp"));
                return("�����㵱��ʦ�ĳ��ͣ��úøɣ�");
        }
        else return("���ϴ���нˮ���������Է����ɻ����û��Ĺ�Ǯ��");
}
/*
string ask_camel()
{
	object ob, me=this_player();
	
	if (me->query("family/family_name")!="����ɽ") {
                command("say ������������" + RANK_D->query_rude(me) +
                        "������ׯ����ʳ������ҹ���");
                command("kick " + me->query("id"));
                return ("С���������㣡");
        }

	if (me->query("rided") || me->query_temp("mark/��")){
		return("�㲻������������");
	}	

	if (query("camel_count") > 20)
                return("���ն�����ʦ�ֵ��������ˣ�"+ RANK_D->query_respect(me)+
                       "Ҫ��ɽ�������ǻ�����˵�ɡ�");

	ob=new("/clone/horse/btcamel");
	ob->move("/d/baituo/btgate");
	add("camel_count", 1);
	ob->set_lord(me);
	ob->set_leader(me);
	me->set_temp("mark/��", 1);
		command("nod");
		say("�������Ը��Ҷ����ݷ�ǣ��һƥ�����������㡣\n");
		return(RANK_D->query_respect(me) + "·��С�ģ���ȥ��飡");
}
*/
