//Code of ShenZhou (5/25/2001)
// npc: /d/city/npc/wei.c
// modified by aln  2 / 98
// modified by kane 4 / 98

inherit NPC;

string ask_book();
string ask_beauty();
int env_cmp(object o1, object o2);

void create()
{
        set_name("Τ����", ({ "wei chunfang", "chunfang", "wei" }) );
        set("gender", "Ů��" );
	set("title", "����Ժ�ϰ���");
//	set("nickname", "¹����");
        set("age", 52);
        set("long", 
            "Τ�����ǵ���¹������컨���ܶ���ΤС�����������"
          "����ϣ��������̴档\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 20);
	set_skill("force", 20);
        set_skill("dodge", 35);
	set_skill("beauty",60);

        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

	set("hooker", 1);
        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "�����Ҿ���Τ������",
            "ΤС��" : "�����ҵĹԶ��ӣ����þ����㡣",
            "����Ժ" : "��������Ժ�������ݳ���ͷһ�ݵ�������ȥ����",
            "here" : "��������Ժ�������ݳ���ͷһ�ݵ�������ȥ����",
            "������"  : (: ask_book :),
	    "beauty" : (: ask_beauty :),
       ]) );

        setup();
        set("amount", 1);
        set("chat_chance", 15);
        set("chat_msg", ({
                "Τ���������˵�������������ұ��µúܣ�ÿ���кü������ˡ�\n",
                "Τ����ŭ������������裬Ҫ����ɲ����ë���ӵ�����Ժ���������ô�ɨ�����˳�ȥ?��\n",
                "Τ��������˵������һ˫�۾���߯�����ģ������Ǹ����\n",
        }) );
        carry_object("/d/city/obj/flower_shoe")->wear();

        carry_object("/d/city/obj/pink_cloth")->wear();
}
private void go_home()
{
	if( !living(this_object()) ) return;
		message_vision("$N˵��:����ʲô��ط����һ�Ҫȥ�ӿ��������ء�\n", this_object());
        message_vision("$N��ɫ���ŵ��뿪�ˡ�\n", this_object());
        this_object()->move("/d/city/lichunyuan");
	message_vision("$N�첽���˹�����\n", this_object());
}
	


void init()
{
        object ob;

        ::init();
        if( environment() != load_object("/d/city/lichunyuan") ) {
		remove_call_out("go_home");
		call_out("go_home", 1);
	}
		else

        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query("hooker"))
	return 1;
}

void greeting(object me)
{
    command("look " + me->query("id"));

    if (me->query("gender")=="����") {
       command("say �㵱��������������������裬���������ɲػض��ӣ����ǲ��ź�̫�࣡");
       command("kick " + me->query("id"));
       message("vision", me->name() +"��Τ����һ���߳����⡣\n",
                environment(me), ({me}));
       me->move("/d/city/nandajie3");
       message("vision", me->name() +"���˴�����Ժ�����˳������Ե��ڵ��ϣ��ĵ�����������\n", 
                environment(me), ({me}));

    }
    else {
    if (me->query("class") =="bonze") {
       command("say �ϣ�" + RANK_D->query_respect(me) 
                +"Ҳ�������������Ժ����");
       command("say �뵱���ҽӹ�һ������������ϴ�ǰһ��Ҫ���һ����������Ӿ͹�����������ҡ�");
    }
    if (me->query("gender")=="Ů��") {
  command("say ��ѽ�������´����Ҳ��Ҥ�ӣ��ɺ���ͳ��");
       command("sigh");
       command("say ��ϧ�Ҷ��Ӳ��ڣ���Ȼ�����ź��㡣");
    }
    command("say ¥��¥�µĹ����ǣ��������ˣ�");
    }
    return ;
}

string ask_book()
{
       object obj, ob = this_player();

       if( !ob->query("hooker") )
              return "��������������������������Ķ������ܸ�����" + RANK_D->query_rude(ob) + "��";

       if( !query("amount") )
              return "�Ѿ����˽����ˡ�";

       obj = new("/d/city/obj/changchun");
       obj->move(ob);
       add("amount", -1);
       message_vision("$N���¶����ͳ�һ" + obj->query("unit") + obj->name() + "�ݸ�$n��\n", this_object(), ob);
       return "���ڽ��÷��Ͻ���㿴����������һ��Ҫ�Ͻ���ѽ��";
}

int env_cmp(object o1, object o2)
{
        string env1, env2;
        object where;
        env1 = (where = environment(o1)) ? base_name(where) : "none";
        env2 = (where = environment(o2)) ? base_name(where) : "none";
        return strcmp(env1, env2);
}

string ask_beauty()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, per = 0;

//	ob_list = sort_array(users(), (: env_cmp :));
	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("per") > per 
		&& ob_list[i]->query("gender") == "Ů��"
		&& !ob_list[i]->query("hooker")
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			per = obj->query("per");
		}
	}

	if ( !obj ) {
	msg ="���ģ����ھ�Ȼһ������Ҷ�û�У��϶���������������å�����ˣ�\n";
	return msg;
	}

	obj->set_temp("top_girl",1);
	name = obj->query("name")+"("+obj->query("id")+")";
	switch( per/5 )
	{
	case 0:
	case 1:
	case 2:
		msg ="���ڡ����ݡ����Ȼ��"+name+"�����������ˣ��߷�����ĸҹ����Ư�����⻹��������\n";
		break;
	case 3:
		msg =name+"����ò����������֮�ʣ���ô�����������أ������ɽ�����ϻ������ӳư����ɣ�\n";
		break;
	case 4:
		msg =name+"����ò�����������ھ������ˣ��Ͽ�����Ҹ��Ϲ����˰ɣ�\n";
		break;
	case 5:
		msg =name+"�����Ǹ��������������������Ժ���ӿͣ��Թ����Ķ��²˳���У����ܿ���̤���ſ��ӣ�\n";
		break;
	case 6 :
		msg =name+"������Ů�·��ɣ����������Ժ�ӣ�����������Ҳ������ĳ����أ�\n";
		break;
	}

	return msg;
}
