// Code of ShenZhou
// /d/changbai/npc/mo-1.c

inherit NPC;

string ask_brother();

void create()
{
        set_name("��һ��", ({ "teng yilei", "teng" }));
        set("nickname", "�ض���ħ");
        set("long",
"�����ǹض���ħ��һ�ס�\n"
"�ɶ�������������򣬿��˲��ٲγ��������ͽ��\n");
        set("gender", "����");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 35);
        set("int", 20);
        set("con", 30);
        set("dex", 20);

        set("max_qi", 900);
        set("max_jing", 600);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 30);
        set("combat_exp", 400000);
        set("score", 20000);

        set_skill("force", 100);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("cuff", 120);
        set_skill("club", 150);
        set_skill("wuxingbu", 100);
        set_skill("wuxing-quan", 100);
        set_skill("weituo-gun", 150);
        set_skill("ding-force", 100);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("parry", "weituo-gun");
        map_skill("club", "weituo-gun");
        map_skill("cuff", "wuxing-quan");

        prepare_skill("cuff", "wuxing-quan");

        set("chat_chance", 5);
        set("chat_msg", ({
"��һ��̾������˵���ܽ�����������Ѱһ�����컨���ȥ�Ĺ��Ӷ�ͻȻʧ���ˡ�\n",
        }));

        set("inquiry", ([
                "������" : "��Ҳ��֪���������ǲ������ˡ�",
                "�컨��" : "�������Һ컨��������ܵ���Ϣ��",
        ]));

        setup();

        carry_object("/d/changbai/obj/tongren")->wield();
        carry_object("/d/xingxiu/obj/diaoqiu")->wear();
}

int accept_object(object who, object ob)
{
        object *obs, obj;

        if( base_name(ob) != "/d/changbai/obj/tiepai" )
                return 0;

        say("��һ�״�е������������ܽ����ڵı�����\n");
        command("cry");

        obs = filter_array(children(__DIR__"club_book"), (: clonep :));
        if( !sizeof(obs) )
                obj = new("/d/changbai/obj/club_book");
        else    obj = new(DRUG_D("cb_renshen"));

        obj->move(this_player());

        message_vision("��һ�״ӻ����ó�һ" + obj->query("unit") + obj->query("name") + "����$N��\n", this_player());

        say("��һ��˵������л����������ܵ���Ϣ��\n");
        call_out("do_destroy", 1, ob);
        return 1;
}        

void do_destroy(object ob)
{
        destruct(ob);
}
