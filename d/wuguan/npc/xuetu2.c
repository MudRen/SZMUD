#include <ansi.h>
inherit NPC;
void create()
{
       set_name("Ů����", ({"xuetu", "dizi"}));
       set("long", "��λС�����С��ϰ�䣬����ֻ�ܰ����������ѧϰ��\n");
       set("title", "���ѧͽ");
       set("gender", "Ů��");
       set("age", 20);
       set("attitude", "friendly");
       set("combat_exp", 3000);       set_skill("dodge", 20);
       set_skill("cuff", 20);
       set_skill("force", 20);       set_skill("parry", 20);
       set_skill("strike", 20);
       set("max_neili", 200);
       set("neili", 200);
       setup(); 
       carry_object("/clone/misc/cloth")->wear();
}   





