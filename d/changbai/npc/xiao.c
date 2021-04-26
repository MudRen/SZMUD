// Code of ShenZhou
// /d/changbai/npc/xiao.c

inherit NPC;

#include "/kungfu/class/shaolin/auto_perform.h";
int auto_perform();

void create()
{
        set_name("��Զɽ", ({ "xiao yuanshan", "xiao" }));
        set("nickname", "����ɮ");
        set("long",
"���˹�ͷ�ڷ����ڲ����棬ֻ¶��һ˫������۾���\n"
"��������Ӣ�ۣ�������ϣ������֮����\n");
        set("gender", "����");
        set("age", 55);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("score", 5000);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 200);

        set("combat_exp", 1800000);

        set_temp("apply/armor", 120);
        set_temp("apply/attack", 20);
        set_temp("apply/dodge", 20);

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("finger", 200);
        set_skill("staff", 200);

        set_skill("buddhism", 100);

        set_skill("hunyuan-yiqi", 200);
        set_skill("shaolin-shenfa", 200);
        set_skill("banruo-zhang", 200);
        set_skill("nianhua-zhi", 200);
        set_skill("pudu-zhang", 200);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "pudu-zhang");
        map_skill("strike", "banruo-zhang");
        map_skill("finger", "nianhua-zhi");
        map_skill("staff", "pudu-zhang");

        prepare_skill("strike", "banrou-zhang");
        prepare_skill("finger", "nianhua-zhi");

        set("chat_chance", 40);
        set("chat_msg", ({
                (: auto_perform :),
        }) );

        setup();

//        carry_object("/clone/weapon/chanzhang")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
