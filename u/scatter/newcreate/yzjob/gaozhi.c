 //CODE BY SCATTER
//JOB NPC
//gaozhi.c

#include <ansi.h>
inherit NPC;

int do_job();
void create()
{
        set_name("½��ֹ", ({ "lu gaozhi", "lu" }));
        set("title","ʦү");
        set("nickname", "������");
        set("long", 
                "½��ֹ����½���࣬���䵱�ɴ�����׳��ʱ�ڴ��ϱ��������壬\n"
                "�˵����𽭺���ԭ����������һλ�쵱�������\n");
        set("gender", "����");
        set("age", 54);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        
        set("max_qi", 1200);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 800000);
        set("score", 50000);
        set("inquiry", ([
                "������" : "������ͽ�ܣ������ԡ�\n",
                "������" : "������ʦ�ܣ��Ѿ����˳�͢ӥȮ����̾��\n",
                                "job" : (: do_job :),
                                "����" : (: do_job :),
        ]));


        set_skill("force", 120);
        set_skill("taiji-shengong", 120);
        set_skill("dodge", 130);
        set_skill("tiyunzong", 130);
        set_skill("cuff", 110);
        set_skill("taiji-quan", 120);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("taiji-jian", 150);
        set_skill("taoism", 80);
        set_skill("literate", 80);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 14, "����");

        setup();
        if (clonep())
        carry_object("/clone/weapon/bailong-jian",
                "/clone/weapon/changjian")->wield();
        carry_object("/d/xixia/obj/robe")->wear();
}

void attempt_apprentice(object me)
{
        command("say ���Ե������������ڳ������������У�С������Ұ�����Ϸ������ڴˣ�������ͽ��");
}

int do_job()
{
        object me=this_player();
        command("consider");
        command("say �������������Ǽ����æ�����Ǹոյõ��鱨����һ��ɱ����֯Ҫ��������ɱ���ݡ�");
        command("say ��һ��Ҫ���Ұѣ����ţ����ţ����ţ����ţ��غá�����ɱ�־͸�ɱ���ۡ�");
        command("say ��׼��һ��Ȼ�󵽶��ű��� (baodao)��");
        return 1;
}
