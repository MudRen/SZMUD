// Code of ShenZhou
// /d/shaolin/npc/zhike
// by xiaojian Aug.18,2000

inherit NPC;
int auto_perform();

string ask_job();
string ask_tiaoshui();
string ask_abandon();
void create()
{
        set_name("֪��ɮ", ({
                "zhike seng",
                "seng",
        }));
        set("long",
                "������������ר������֪��ɮ����������ί�ɸ������ֵ��ӵ���ˮ���⡣\n"
                "����һϮ�಼ɮ�£�����Ц�Ǻǵġ�\n"
        );
 
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 30);
        set("shen_type", 1);
        set("str", 28);
        set("int", 26);
        set("con", 29);
        set("dex", 28);
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("neili", 6000)
;
        set("max_neili", 6000);
        set("jiali", 100);
        set("combat_exp", 600000);
        set("score", 500000);

        set_skill("force", 120);
        set_skill("hunyuan-yiqi", 120);
        set_skill("dodge", 120);
        set_skill("shaolin-shenfa", 120);
        set_skill("cuff", 120);
        set_skill("luohan-quan", 120);
        set_skill("jingang-quan", 120);
        set_skill("club", 120);
        set_skill("weituo-gun", 120);
        set_skill("strike", 120);
        set_skill("sanhua-zhang", 120);
        set_skill("hand", 120);
        set_skill("qianye-shou", 120);
        set_skill("finger", 120);
        set_skill("nianhua-zhi", 120);
        set_skill("parry", 120);
        set_skill("buddhism", 120);
        set_skill("literate", 120);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "nianhua-zhi");
        map_skill("strike", "sanhua-zhang");
        map_skill("hand", "fengyun-shou");
        map_skill("claw", "longzhua-gong");
        map_skill("parry", "nianhua-zhi");

        prepare_skill("finger", "nianhua-zhi");
        prepare_skill("strike", "sanhua-zhang");

        create_family("������", 37, "����");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: auto_perform :), }));

        set("inquiry", ([
            "����" : (: ask_tiaoshui :),
		    "��ˮ" : (: ask_tiaoshui :),
		    "job" : (: ask_tiaoshui :),
			"abandon" : (: ask_abandon :),
			"����" : (: ask_abandon :),
        ]));
        
        setup();

        carry_object("/d/shaolin/obj/cloth")->wear();
}
#include "/kungfu/class/shaolin/auto_perform.h"

#include "/d/shaolin/npc/tiaoshui1.h"
