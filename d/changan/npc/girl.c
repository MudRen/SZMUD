              // /d/changan/npc/girl.c
// ��1���޸�
// by bravo
// Email
// 02-1-3
// ������ҳ��ַ
// �ļ�����  NPC  
inherit NPC;
void create()
   {
     set_name("��������", ({ "maihua guniang","girl" }));
     set("long","����һλһ����Ϊ���Ĺ���\n");
     set("age", 18+random(20));
      set("gender","Ů��");
      set("attitude","friendly");
add_money("coin",20+random(50));
     set("str", 20);
     set("dex", 20);
     set("con", 20+random(20));
     set("int", 20);
      set("jiajing",100);
      set("max_jingli",100);
      set("jingli",100);
      set("max_neili",100);
      set("neili",100);
      set("eff_jing",100);
      set("jing",100);
      set("eff_qi",100);
      set("qi",100);
      set("inquiry", ([
"Ұ��" : "��ô,���·�ߵ�Ұ����?\n",
]) );

setup();
}


