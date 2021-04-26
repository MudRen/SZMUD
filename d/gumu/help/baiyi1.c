// longnv.c ������Ů
// by April 01/08/06
// update 01/08/06
// update blacko 01/08/12

#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
        object bj;

        set_name("������Ů", ({ "baiyi girl", "girl"}));
        set("long", 
                "������һϮ��ɴ��İ��£������������ס�\n");
        set("gender", "Ů��");
        set("age", 26);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 25);
        set("con", 25);

        set("dex", 30);
        
        set("max_qi", 4000);
        set("max_jing", 5500);
        set("jiali", 200);
        set("neili", 6000);
        set("max_neili", 6000);
                set("jingli",4000);
                set("eff_jingli",4000);
                set("max_jingli",4000);

        set("combat_exp", 500000);
        set("score", 5000);

        set_skill("force", 150);
        set_skill("yunu-xinjing", 150);
        set_skill("cuff", 150);
        set_skill("meinu-quan", 150);
        set_skill("sword", 150);
        set_skill("yunu-jianfa", 150);
        set_skill("finger", 150);
        set_skill("suhan-zhi", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("feiyan-gong", 150);
                set_skill("bee-training",150);
                set_skill("lovingness",150);
                set_skill("parry",150);
                set_skill("suxin-jue",150);
                set_skill("zuoyou-hubo",150);
                set_skill("throwing",150);
                set_skill("whip",150);
                set_skill("jueqing-bian",150);
                set_skill("finger",150);
                set_skill("suhan-zhi",150);

        map_skill("force", "yunu-xinjing");
        map_skill("dodge", "feiyan-gong");
        map_skill("cuff", "meinu-quan");
        map_skill("parry", "yunu-jianfa");
        map_skill("sword", "yunu-jianfa");

        prepare_skill("cuff", "meinu-quan");

        create_family("��Ĺ��", 5, "����");


        set("chat_chance_combat", 50);

        set("inquiry", ([
                "��Ů�ľ�" : (: ask_me :),
                "xinjing" : (: ask_me :),
        ]));

        setup();

                carry_object("/clone/weapon/changjian")->wield();
                carry_object("/d/gumu/obj/white_silk")->wear();
        
}

void init()
{
        object ob;

        ::init();
        return;
       
}

string ask_me()
{
        mapping fam;
        int lv1 = (int)this_player()->query_skill("quanzhen-xinfa", 1);
        int lv2 = (int)this_player()->query_skill("yunu-xinfa", 1);

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "��Ĺ��") {
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";
        return;
        }

        if (lv1 < 30 || lv2 < 30) {
                if (lv1 < 30 && lv2 <30) {
                command("say " + RANK_D->query_respect(this_player()) +
                        "��Ů�ľ���Ҫ�ϳ��ڹ����ܼ�Ԧ�㻹�ǻ�ȥ�ɡ�");
                }
                else if (lv1 < 30) {
                command("say " + RANK_D->query_respect(this_player()) +
                        "��ȫ���ķ����о��ƺ���̫��");
                }
                else {
                command("say " + RANK_D->query_respect(this_player()) +
		"�Թ�Ĺ�ķ��������ƺ���̫��");
                }
        return RANK_D->query_respect(this_player()) +
                        "���в��㣬������η��������ķ��أ�";
        }

        this_player()->set_skill("yunu-xinjing", 30);
        this_player()->delete_skill("quanzhen-xinfa");
        this_player()->delete_skill("yunu-xinfa");
        this_player()->add("max_neili" ,30);
        command("congra " + this_player()->query("id"));
        command("say " + RANK_D->query_respect(this_player()) +
                "�Ĺ�Ĺ�书���о�����");
        return RANK_D->query_respect(this_player()) +
                        "��ϲ�㣡";
;
}