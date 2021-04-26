// Code of ShenZhou
// wang.c

inherit NPC;

int ask_me();

void create()
{
        set_name("��С��", ({ "wang xiaoer", "wang" }) );
        set("gender", "����" );
        set("age", 21);
        set("long", "���Ǹ����͵Ĺ������ӣ�һ���뺷֮ɫ��\n");
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
        set("combat_exp", 5000);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

	set("shen_type", -1);
        set("str", 28);
        set("dex", 25);
        set("con", 20);
        set("int", 17);
        set("attitude","heroism");
        set("inquiry", ([
		"��" : (: ask_me :),
		"͵��" : (: ask_me :),
        ]) );
	set("book_count", 1); 
        setup();
	carry_object("/clone/armor/cloth")->wear();
        add_money("coin", 200);
}
/*void init()
{
        ::init();
        add_action("do_bihua", "bihua");
}
*/

int ask_me()
{
	if ((int)this_player()->query_temp("marks/��3")) {
		say(
"��С����¶�׹⣬��" + this_player()->name() + "������ɱ�˲���ͷ��أ����Ѿ�\n"
"�������㻹���Ź��ң����Ӹ���ƴ�ˣ�\n");
		set_temp("apply/attack", 30);
     		set_temp("apply/defense", 30);
		this_object()->kill_ob(this_player());
		return 1;
	} else {
	say(
"��С������" + this_player()->name() + "һ�ۣ������ں���˵����\n"
"����������͵�ģ���Ҫ��������������Ҳ�ǳ����������ģ��ѵ�\n" 
"��֪������˭��ȭͷ��˭˵�������㲻�������Ǻã����������У�\n"
"Ҫ����Ӯ�ˣ������ϰ�˫���������̫̫�������һ����������\n"
"��������Ҫ���ˣ��͸������ų�ȥ�������ţ��Ҳ��ұȻ����£�\n");
	this_player()->set_temp("marks/��2", 1);
	return 1;
	}
}

int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if( ob->query_temp("marks/��2") ) {
        say(ob->name() + "����С��˵���ðɣ���"
		 + RANK_D->query_self_rude(ob) + "��ͬ�������С�\n");

          me->set_temp("challenger", ob);
          ob->delete_temp("marks/��2");
          return 1;
        }
        else {
	  say("��С�����ͷ��Ķ�" + ob->name() + "˵������ү�������������жļ���û�ա�\n");
          return 0;
	}
}

int chat()
{
        object me = this_object();
        object ob = me->query_temp("challenger");
        object book, *obs;
        int my_max_qi, his_max_qi;

        if( !objectp(ob) ) return ::chat();

        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting(ob)) return ::chat();

        me->delete_temp("challenger");

        if (me->is_fighting()) return ::chat();

        if ( !present(ob, environment()) ) return ::chat(); 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {

	   if (query("book_count") >= 1) {
		obs = filter_array(children(__DIR__"obj/sword_book.c"), (: clonep :));
        	if (sizeof(obs) > 2){
        		command("fear"); 
        		command("escape");
        		destruct(me);
			return 1;
           	}
                say(
"��С����" + ob->name() + "˵���������Ӯ���ң���˵ʲô�Ҷ������ţ�����Ͱ�\n"
"       Ǯ����̫̫��ȥ�����⣬�Ȿ��Ҳ�������ˡ�����ǰЩ���ӻ�ɽ�ɴ���\n"
"       ·����������Ъ��ʱ���µġ�\n"
                );
		book = new(__DIR__"obj/sword_book");
                book->move(ob);
		ob->set_temp("marks/��3", 1);
		message_vision("$N����$nһ���顣\n", me, ob);
		add("book_count", -1);
                return ::chat();
	   }
	   else {
		say(
"��С����" + ob->name() + "˵���������Ӯ���ң���˵ʲô�Ҷ������ţ�����Ͱ�\n"
"       Ǯ����̫̫��ȥ��\n"

		    );
                return ::chat();
           }
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
		say(
"��С������" + ob->name() + "Ʋ��Ʋ�죬˵����������㱾�»���\n"
"��Ӣ�ۣ������ҹԹԵ�����ȥ�ɣ�\n"
                );
                message("vision",
ob->name() + "�ԹԵ�ſ�ڵ��ϣ��Ӷ������˳�ȥ��\n", environment(ob), ({ob}) );
                ob->move("/d/village/temple1");
                message("vision",
ob->name() + "�Ӷ������˳�����\n", environment(ob), ({ob}) );
                return ::chat();
        }
        return ::chat();
}

