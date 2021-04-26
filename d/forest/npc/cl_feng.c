// Code of ShenZhou
// /d/huanghe/changle/npc/fengliang.c ����
// by aln 2 / 98

#define TUCHAN "/d/forest/obj/cl_tuchan"

inherit NPC;

void create()
{
        set_name("����", ({ "feng liang", "feng" }));
        set("title", "������������");
        set("long", 
                "���Ǹ��ߴ�����꺺�ӣ�������Žڱޡ�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 600);
        set("max_jing", 300);
        set("max_neili", 400);
        set("neili", 400);
        set("jiali", 20);
        set("combat_exp", 90000);
        set("score", 4500);

        set_skill("force", 75);
        set_skill("dodge", 75);
        set_skill("parry", 75);
        set_skill("cuff",  75);
        set_skill("whip",  80);

        set_skill("ding-force", 75);
        set_skill("wuxingbu", 75);
        set_skill("wuxing-quan", 75);
        set_skill("canglang-bian", 80);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "canglang-bian");
        map_skill("whip", "canglang-bian");

        prepare_skill("cuff", "wuxing-quan");

        set("chat_chance", 10);
        set("chat_msg", ({
                "����˵�����������������������ʹ�Žڱޣ����Ǻ����ӹ���ȥ��\n",
                "����˵�������ְ��˾ͽ����밳���й����Ľ��飬����ȥ�ݷ������˼ҡ�\n",
        }) );

        set("inquiry",([
                "������" : "��������Ȼ���ҵľŽڱ޶����ˡ�",
		"���ְ�" : "��Ҳ��Ҫ�����ְ��ɽ��",
                "˾ͽ���" : "˾ͽ�����¾����ֵ��ҵ��¡�",
                "˾ͽ��" : "��˵���ְ�ļ������ҷ��Ϻ���������",
                "�Žڱ�" : "�Žڱ����Ҳ������ˣ�������Ū�����ӵ������á�",
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
 //     carry_object("/clone/weapon/changbian")->wield();
}

int accept_object(object who, object ob)
{
        object obj;

        if( (string)ob->query("skill_type") != "whip"
        ||  (int)ob->query("value") < 100
        ||  query_temp("weapon") )
                return notify_fail(name() + "���˰��֣�˵�����㻹���Ը��������ðɡ�\n");

        command("joythank " + who->query("id"));
        call_out("do_wield", 1, ob);
        obj = new(TUCHAN);
        obj->move(who);
        message_vision("$N��һ" + obj->query("unit") + obj->name() + "�͸�$n��\n", this_object(), who);
        command("say ����һ��СС���⣬��������¡�");
        return 1;
}

void do_wield(object ob)
{
        "/cmds/std/wield"->do_wield(this_object(), ob);
}
