//Cracked by shenzhou
// tea girl.c 
// �ƶ�  May 2002

inherit NPC;

void create()
{
        set_name("���", ({ "cha gu", "girl" }) );
        set("gender", "Ů��" );
        set("age", 12);
        set("long", "��������Ϻ���С��Ů����Ļ��ܵ����������ѳ���������µ��ˡ�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");        
        setup();
        carry_object("/d/sanbuguan/obj/skirt")->wear();
}
