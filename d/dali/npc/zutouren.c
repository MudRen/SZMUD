// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("��ͷ��", ({ "zu touren", "offial" }));
        set("long", 
"��λ�ǰ������ͷ�ˣ�Դ�ڻ������ǰ��ᣬ�����Ա�䲻�Ӹ�λ��\n"
"ȴ�����Ŵ��������ʵȨ��������Ա���������˾����£���Ϊѷɫ��\n"
"�����ֻ��һ���ɫ�Խ��¼�����ӣ���һͷ��Ϊ���۵İװ�ͷ���� \n"
"���ڴ���˾�������ף������˺���������\n");
        set("gender", "����");
        set("age",50 );
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("combat_exp", 7000+random(2300));

        set_skill("force", 40);
        set_skill("dodge", 35);
        set_skill("unarmed", 50);
        set_skill("parry", 60);
        setup();


	 carry_object("/d/dali/npc/obj/baicloth")->wear();

}


