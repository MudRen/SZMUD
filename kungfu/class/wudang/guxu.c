// Code of ShenZhou
// guxu.c ����
// Modified by xQin 04/01

#include "daozhang.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();

void create()
{
        set_name("�������", ({ "guxu daozhang", "guxu" }));
        set("long",
                "����������ҵĵ��ӹ��������\n"
                "��������ʮ�꣬�����䵱�ɵ����¡�\n"
                "��Ҳ����ǵ����������е�ٮٮ�ߡ�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 32);
        set("int", 32);
        set("con", 32);
        set("dex", 32);

        set("max_qi", 1500);
        set("max_jing", 1200);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jiali", 60);
        set("combat_exp", 250000);
        set("score", 8000);

        set_skill("force", 120);
        set_skill("taiji-shengong", 120);
        set_skill("dodge", 120);
        set_skill("tiyunzong", 120);
        set_skill("cuff", 120);
//      set_skill("taiji-quan", 100);
        set_skill("strike", 120);
        set_skill("mian-zhang",120);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("taiji-jian", 100);
        set_skill("literate", 101);
        set_skill("taoism", 120);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "mian-zhang");
        map_skill("sword", "taiji-jian");

        prepare_skill("strike", "mian-zhang");

        create_family("�䵱��", 3, "����");
        set("class", "taoist");

        set("inquiry",
                ([
                        "���¾�" : (: ask_me :),
                ]));

        set("book_count", 1);

        setup();
//      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}


void init()
{
        object me = this_player();

        ::init();

        if ( me->query("family/family_name") == "�䵱��"
                && me->query("wudang/offerring") > me->query("age")*2 )
                me->set_temp("mark/����", 1);
}



string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";

        if (query("book_count") < 1)
                return "�������ˣ����ɵĵ����澭���ڴ˴���";

        add("book_count", -1);
        ob = new("/d/wudang/obj/daodejing-ii");
        ob->move(this_player());

        return "�ðɣ��Ȿ�����¾������û�ȥ�ú����С�";
}


// End of file
