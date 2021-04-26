// Code of ShenZhou
// /d/huange/npc/tc_wang.c

#define TIECHA  "/d/huanghe/obj/tiecha"

inherit NPC;

string ask_join();

void create()
{
        set_name("������", ({ "wang laoliu", "wang" }));
        set("title", "�����СͷĿ");
        set("long",
"����һλ��ʮ����ı��δ󺺡�\n");
        set("gender", "����");
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 500);
        set("max_jing", 400);
        set("max_neili", 400);
        set("neili", 400);
        set("jiali", 25);
        set("combat_exp", 50000);
        set("score", 2000);

        set_temp("apply/armor", 20);

        set_skill("force", 65);
        set_skill("dodge", 65);
        set_skill("parry", 65);
        set_skill("cuff",  65);
        set_skill("pike",  65);

        set_skill("ding-force", 65);
        set_skill("wuxingbu", 65);
        set_skill("wuxing-quan", 65);
        set_skill("liuhe-qiang", 70);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "liuhe-qiang");
        map_skill("pike", "liuhe-qiang");

        prepare_skill("cuff", "wuxing-quan");

        set("inquiry", ([
                "�����" : "�����������лƺ��������첻�£��ز��£����ʵ��϶������������ʡ�",
                "�ȵ�ʤ" : "�ҼҰ����ȴ�ү����ɽ���������š���Ωһ���ˣ��淨������˫��",
                "���Ʒ���ʹ��" : "���Ʒ���ʹ�����뽭�����������ŵü���β�ͣ��㵽�����ȥ����ͷ�ڹ꣡",
                "���͵�" : "��������͵�ʲô���Ʒ���ʹ�ߣ����Ӳ��£�",
                "�����" : "������ڱװ��Ϳ๦�ߣ��ĵð������Ρ�",
                "���" : (: ask_join :),
        ]));

        setup();

        carry_object("/clone/weapon/sangucha")->wield();
}

int accept_object(object who, object ob)
{
        object obj;

        if( base_name(ob) != CORPSE_OB ) return 0;

        if( ob->query("my_killer") != who->query("id") ) {
                say("��������ŭ�����㵱���Ƕ���ӣ�����������\n");
                return 0;
        }

        if( ob->query("combat_exp") < who->query("combat_exp") ) {
                command("sigh");
                command("say ������Ӳ�Ķ������㻹�ǹ��ɣ�");
                return 0;
        }

        if( who->query_temp("bangs/fam") == "�����" ) {
                command("bored " + who->query("id"));
                command("say ���Ѿ����ֵ��ˣ�˭����֪��˭��");
                return 0;
        }

        command("nod");

        obj = new(TIECHA);
        obj->move(who);
        who->set_temp("tc_wang", 1);
        message_vision("$N��һֻС���潻��$n��\n", this_object(), who);
        command("say �����ģ�ƾ��С������Ϳ���ȥ��������ˡ�\n");
        call_out("do_destroy", 1, ob);
        return 1;
}

void do_destory(object ob)
{
        if( ob ) destruct(ob);
}

string ask_join()
{
        object me  = this_player();

        if( me->query_temp("bangs/fam") == "�����" )
	        return "�����Ĳ����ģ���";

        if( (int)me->query("combat_exp") > 100000 ) 
                return "��Ī���ǿ���Ц�ɣ���";

        if( me->query_temp("tc_wang") )
                return "�Ҳ����Ѿ������������ȥ���������𣿣�";

        return "Ҳ��֪���㵨�Ӵ󲻴�ȥɱ����Ū��ʬ������";
}
