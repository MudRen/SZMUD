#include <ansi.h>
inherit NPC;
void create()
{
       set_name("�е���", ({"xuetu", "dizi"}));
       set("long", "������ݵ�һ��ѧͽ����С�ͱ������ͽ���ѧ�䡣\n");
       set("title", "���ѧͽ");
       set("gender", "����");
       set("age", 18);
       set("attitude", "friendly");
       set("combat_exp", 2000);       set_skill("dodge", 20);
       set_skill("cuff", 20);
       set_skill("force", 20);       set_skill("parry", 20);
       set_skill("strike", 20);
       set("max_neili", 200);
       set("neili", 200);
       setup(); 
       carry_object("/clone/misc/cloth")->wear();
}   





