//by qiuly
//����
#include <ansi.h>
inherit NPC;


void create()
{
                  set_name("����", ({ "hui lang", "lang" }) );
                  set("race", "Ұ��");
                  set("age", 25);
                  set("long", "һֻ�ƺ��Ѿ����˼���Ļ��ǣ�������ݺݵض����㡣\n");
                  set("attitude", "aggressive");
                  set_weight(200000);
                  set("max_qi", 100);
                  set("max_jing", 100);
                  set("max_jingli", 100);


                  set("str", 30);
                  set("con", 80);
                  set("dex", 30);
                  set("int", 10);

                  set("combat_exp", 20000);

                  set_temp("apply/attack", 10);
                  set_temp("apply/damage", 10);
                  set_temp("apply/armor", 10);

                  setup();
}



