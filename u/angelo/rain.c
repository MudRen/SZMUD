// Code of ShenZhou
inherit NPC;

void create()
{
          set_name("���", ({ "rain", "nu", "girl" }));

        set("long", 
      " һ�����ĺܺÿ���С����.ֻ��ü�����һ˿��Թ. \n"); 
 set("gender", "Ů��");
          set("age", 23);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        setup();
        set("chat_chance", 8);
        set("chat_msg", ({
"��Ů��������,"����ʱ�֣�����ҶƮ�أ�ң�����죬�ǳ�����"��\n",
"��Ů��������,"���������Ƹ�Ƽ����ȥ������������������ãã"��\n",
"��Ů��������,"����ˣ�ǧ���⽭��ˮ�磬��������"��\n",
"��Ů��������,"�������ھƻᣬԸ�����Ϻ�����Բʱ��Я�������Ӣ��"��\n",


        }) );


	 carry_object("/d/city/obj/jin_ao.c")->wear();
        carry_object("/d/jiaxing/obj/yaoqin")->wield();

}


