// Code of ShenZhou
// shihou.c ������
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("������", ({ "chuchen zi", "chuchen" }));
        set("nickname", "�����ɰ�ʦ��");
        set("long", 
                "�����Ƕ�����İ˵��ӳ����ӡ�\n"
                "�����Ű��֣��������յĸ����ֳ����ء�\n");
        set("gender", "����");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 15);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 15);
        set("combat_exp", 100000);
        set("score", 20000);

        set_skill("force", 60);
        set_skill("huagong-dafa", 40);
        set_skill("dodge", 60);
        set_skill("zhaixinggong", 50);
        set_skill("strike", 50);
        set_skill("parry", 50);
        set_skill("chousui-zhang", 50);
        set_skill("staff", 80);
        set_skill("tianshan-zhang", 80);
//      set_skill("literate", 50);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("strike", "chousui-zhang");

        create_family("������", 2, "����");

        setup();
        carry_object("/d/xingxiu/obj/staff1")->wield();
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
}

void init()
{
        object ob;
        mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()
        && file_name(environment(this_object())) == "/d/xingxiu/xxroad5" ) {
                myfam = (mapping)ob->query("family");
                if ((!myfam || myfam["family_name"] != "������") &&
                        (!wizardp(ob))) {
                        remove_call_out("do_killing");
                        call_out("do_killing",1,ob);
                }
        }
        if (interactive(ob=this_player()) && !this_object()->is_killing(ob)
        && present("lanyu bo",ob)) {
           message_vision(
           HIY "$Nһ����$n��ŭ�������󱲣���������ʦ�ű����������\n"NOR, this_object(), ob);
        command("follow "+ob->query("id"));
        kill_ob(ob);
        ob->start_busy(1);
      
        }
}

void do_killing(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}

void attempt_apprentice(object ob)
{
        command("say ���ɻ�û��������ͽ�ء�");
        //command("recruit " + ob->query("id"));
}
