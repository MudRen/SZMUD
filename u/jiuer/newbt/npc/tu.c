//Cracked by jiuer
// 06/1/2002

inherit NPC;
string ask_camel();

void create()
{
        set_name("�¶�ѷ", ({ "tu ersun", "tu" }));
        set("long", "�¶�ѷ�Ǹ�������ˣ����Ÿ�ӥ���ǣ�����������ŷ�����������շ�\n");
        set("gender", "����");
        set("age", 25);

    set_skill("dodge", 30);
	set_skill("chanchubu", 30);
    set_skill("parry", 30);
    set_skill("force", 30);
	set_skill("hamagong", 35);
	set_skill("strike",30);
	set_skill("training",70);
    map_skill("dodge","chanchubu");
	map_skill("force","hamagong");

        set("str", 28);
        set("int", 21);
        set("con", 24);
        set("dex", 21);

        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 550);
        set("max_neili", 550);
        set("jiali", 10);
        set("combat_exp", 5000);

        set("attitude", "peaceful");
        set("shen_type", -1);
        set("inquiry", ([
			"����" : (: ask_camel :),
			"����" : (: ask_camel :),
			"camel" : (: ask_camel :),

        ]));

        create_family("����ɽ", 3 , "����");
	setup();
	carry_object("/d/baituo/obj/wcloth")->wear();
	add_money("silver",3);
}
void init()
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

string ask_camel()
{
	object ob, me=this_player();
	
	if (me->query("family/family_name")!="����ɽ") {
                command("say ������������" + RANK_D->query_rude(me) +
                        "������ׯ����ʳ������ҹ���");
                command("kick2 " + me->query("id"));
                return ("С���������㣡");
        }

	if (me->query("rided") || me->query_temp("mark/��")){
		return("�㲻������������");
	}	

	if (query("camel_count") > 20)
                return("���ն�����ʦ�ֵ��������ˣ�"+ RANK_D->query_respect(me)+
                       "Ҫ��ɽ�������ǻ�����˵�ɡ�");

	ob=new("/clone/horse/btcamel");
	ob->move("/d/baituo/tuopeng");
	add("camel_count", 1);
	ob->set_lord(me);
	ob->set_leader(me);
	me->set_temp("mark/��", 1);
		command("nod");
		say("�¶�ѷ���ݷ�ǣ��һƥ�����������㡣\n");
		return(RANK_D->query_respect(me) + "·��С�ģ���ȥ��飡");
}
