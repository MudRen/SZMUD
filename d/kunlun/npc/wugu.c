#include <ansi.h>
inherit NPC;
inherit F_DEALER;
void create()
{
            set_name("���", ({ "wu gu", "wu" }));
        set("shen_type", 0);
        set("age",31);
        set("gender", "Ů��");
        set("per",7);
        set("long",
                  "�����Ǻ�̫���С���ţ�ֻ����һ���׵�������˽�һ�㣬˫���������
�����������۾����������������ǳ��ŷ��䡣\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "�����" : "�Ǹ���������һ���һ�ɱ������\n",
                  "��̫��" : "�������ɷ�\n",
                 "��" : "��Ҳ��֪����ʲô����\n",
                   "��֬��" : "��֬���ر��㣬���ڻ�԰���˺öࡣ\n",
        ]));
      
  setup();
          carry_object("/d/city/obj/pink_cloth")->wear();
}

