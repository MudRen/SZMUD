#include <ansi.h>
inherit NPC;
void create()
{
         int aa = random(5) + 2;
         int bb = random(3);
         set_name("����", ({"ahun", "hun"}));
         set("gender", "����");
         set("age", 30);
         set("title", "Ȫ�ݵ�ͷ��");
         set("long", "����Ȫ�ݳ����������С��å�����첻����ҵ�����ֺ��У��������ǡ������Լ�ѧ�������书�������۸���С��\n");
         set("chat_chance", 10);
         set("chat_msg", ({ 
           "С���˵��:����Ȫ�ݶ������ӵĵ��̡�\n",
           "С���˵��:��Ҳ��ȥ�����������ӵ����š�\n",
           "С���˵��:��˵������˸�ʲô��ë��ݣ������Ӳ���ƽ������\n"
           "С���˵��:�����������ҵ����ϻ죬�͵���Т�����ӡ�\n",}));         set("combat_exp", 500*aa);
         set("attitude", "aggressive");
         set("shen_type", -1);
         set("max_qi", 100*bb);
         set("max_ji", 100);
         set("max_jingli", 200);
         set("max_neili", 300);
         set("neili", 300);
         set("jiali", 10*bb);
         set_temp("apply/attack", 20);
         set_temp("apply/defense", 20);
         set_skill("parry", 10+10*bb);
         set_skill("dodge", 10+10*bb);
         set_skill("blade", 10+10*bb);
         set_skill("force", 40);
         set_skill("huntian-qigong", 40);
         map_skill("force", "huntian-qigong");
         setup();
         carry_object("/clone/misc/cloth")->wear();
         carry_object("/clone/weapon/gangdao")->wield();
 }

