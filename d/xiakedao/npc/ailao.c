//Cracked by Roath
// ailao.c ������
// qfy Sept 8, 1996.

inherit NPC;

void create()
{
        set_name("������", ({ "ai lao", "ai", "lao" }));
        set("long", 
"����������С�������ȷǷ������˲���С����������ʦ�ܸ�����\n"
"�չ��Ѿã������������������书֮�ߣ�ȴ�����𾪡�\n");
        set("gender", "����");
        set("age", 75);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 27);
        set("int", 25);
        set("con", 25);
        set("dex", 26);
        
        set("max_qi", 3200);
        set("max_jing", 2100);
        set("neili", 2800);
        set("max_neili", 2800);
        set("combat_exp", 1500000);
        set("score", 5000);

        set_skill("force", 170);
        set_skill("dodge", 170);
        set_skill("parry", 180);
        set_skill("blade", 180);
        set_skill("sword", 170);
        set_skill("strike", 170);
        set_skill("liangyi-dao", 180);
        set_skill("huashan-jianfa", 170);
        set_skill("hunyuan-zhang",170);
        set_skill("huashan-shenfa", 170);
        set_skill("zixia-gong", 170);
        set_skill("cuff", 170);
        set_skill("pishi-poyu", 170);
        set_skill("ziyin-yin", 170);
        set_skill("zhengqi-jue", 170);

        map_skill("cuff", "pishi-poyu");
        map_skill("force", "zixia-gong");
        map_skill("force", "zixia-gong");
        map_skill("parry", "huashan-jianfa");
        map_skill("blade", "liangyi-dao");
        map_skill("sword", "huashan-jianfa");
        map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "huashan-shenfa");
        
        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "pishi-poyu");

        create_family("��ɽ��", 12, "����");


        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}

#include "/d/xiakedao/npc/zhanglao.h"