// Code of ShenZhou
// mingyue.c ����
// xQin 12/00

inherit NPC;

void create()
{
        set_name("����", ({ "mingyue", "daotong", "dao", "tong"}));
        set("long",
                "�����䵱ɽ��С��ͯ�������ۣ�ͷ����٣�ƽʱ�����չ�����ҵ������ʳ��\n");
        set("gender", "����");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);

        set("max_qi", 250);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

        set("combat_exp", 8000);
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("cuff", 20);
        set_skill("strike", 20);
        set_skill("parry", 20);

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);

        create_family("�䵱��", 5, "����");
        set("inquiry", ([
		"���޼�" : "Сʦ�壿������֪�������ڲ�����û�У���Ҷ�������������",
	]));
	
        setup();
        
        carry_object("/d/wudang/obj/greyrobe")->wear();
}

void init()
{
        set("inquiry/�䵱","ƶ�������䵱�ɵ��ӣ���֪��λ" + RANK_D->query_respect(this_player()) +"�кμ��̣�");
        set("inquiry/�䵱��","ƶ�������䵱�ɵ��ӣ���֪��λ" + RANK_D->query_respect(this_player()) +"�кμ��̣�");
        set("inquiry/name","ƶ���������£���֪��λ" + RANK_D->query_respect(this_player()) +"�кμ��̣�");
        set("inquiry/������","��ʦү�������棬��֪��λ"+ RANK_D->query_respect(this_player()) +"�Ƿ���Ҫ����������ʦү��");
}
