// Code of ShenZhou
// /d/hangzhou/npc/gu.c
// by aln  2 / 98

inherit NPC;

#include <ansi.h>

string ask_book();

void create()
{
        set_name("������", ({ "gu yanwu" , "gu" }));
        set("gender", "����");
        set("age", 55);
        set("long", 
"���ָ����ݣ���Ŀ��ڡ�\n"
"����ͤ�֣�������ɽ��ʿ��\n");
        set("shen_type", 1);
        set("combat_exp", 2000);

        set("str", 20);
        set("int", 30);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 500);
        set("max_jing", 500);

        set("score", 10000);

        set_skill("dodge", 30);
        set_skill("sword", 30);

        set("inquiry", ([
                 "�����鼭�ԡ�" : (: ask_book :),
                 "���鼭��" : (: ask_book :),
                 "��׫" : (: ask_book :),
                 "book" : (: ask_book :),
        ]));

        setup();

        carry_object("/d/dali/npc/obj/dagger")->wield();
}

string ask_book()
{
        object ob;

        if( !(ob = present("mingshi", this_player())) )
                return "û��ԭ�壬����ô��׫��";

        if( ob->query("checked") )
                return "���Ѿ���׫�������ˡ�";

        ob->set("checked", 1);
        message_vision("�����佫���ĺ��޸��˼�������ͬʱҲ��$N������һ�¡�\n", this_player());
        if( (int)this_player()->query_skill("literate", 1) < 60 )
                this_player()->improve_skill("literate", 
                          10 * this_player()->query("int"));

        return "��׫��ʷ����һ�����£��Ϸ��Ѿ�����Ϊ�ˡ�";
}
