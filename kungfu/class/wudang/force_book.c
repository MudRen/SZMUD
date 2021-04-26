//Last Update by Scatter
//1/3/2002
inherit ITEM;
#include <ansi.h>
int do_tuna(string arg);
int respirating(object me);
int halt_respirate(object me);


void setup()
{}

void init()
{
                  add_action("do_tuna", "lianjing");
}

void create()
{
        set_name(HIW"̫��ʮ����"NOR, ({ "shu", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����װ�飬������������Ļ��˲��ٴ�������(lianjing)�����ơ�\n����ֻ�ʺϼӿ������ٶȣ��������������������þ�����\n");
                set("value", 5000);
                set("material", "paper");
                set("skill", ([
                        "name": "force",        // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    30,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    30      // the maximum level you can learn
                ]) );
        }
}
int do_tuna(string arg)
{
                  object me = this_player();
        int respirate_cost;

                  object where;

                  seteuid(getuid());
                  where = environment(me);

                  if (!present("shu", me))
                                         return 0;
                  if( base_name(where) != "/d/wudang/long_shiliang" )
                                                                                return notify_fail("���ﲻ������̫��ʮ���ƣ�\n");
 
                                  if( me->query("shen")*2 < me->query("combat_exp") )
                                                                                return notify_fail("�����������̫�ͣ���̫��ʮ���ƿ��ܻᵼ���߻���ħ��\n");

                  if (where->query("pigging"))
                                         return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

                  if (where->query("sleep_room"))
                                         return notify_fail("��˯���ﲻ�ܴ��������Ӱ�����ˡ�\n");

                  if (me->is_busy() || me->query_temp("pending/exercising"))
                                         return notify_fail("��������æ���ء�\n");

                  if( me->is_fighting() )
                                         return notify_fail("ս���в������ڹ������߻���ħ��\n");

                  if( !stringp(me->query_skill_mapped("force")) )
                                         return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

                  if( !arg || !sscanf(arg, "%d", respirate_cost))
                                         return notify_fail("��Ҫ�����پ�������\n");
                  if (respirate_cost < 10)
                                         return notify_fail("����ڹ���û�дﵽ�Ǹ����磡\n");


                  if( (int)me->query("jing") < respirate_cost )
                                         return notify_fail("�����ڵľ�̫���ˣ��޷�������Ϣ����ȫ������\n");

                  if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
                                         return notify_fail("���������������޷�������Ϣ��������\n");

                  write("�㰴���ڹ��ķ������������������ù���ȫ��ů��������������\n");

                  me->set_temp("pending/respirate", 1);
                  me->set_temp("respirate_cost", respirate_cost);
                  message_vision("$N��ϥ���£���ʼ����������\n", me);
                  me->start_busy((: respirating :), (:halt_respirate:));
                  return 1;
}

int respirating(object me)
{
                  int cost;
                  object  where = environment(me);
                  int respirate_cost = (int)me->query_temp("respirate_cost");
        int jingli_gain = 2 + (int)me->query_skill("force",1) / 5;
                  if (respirate_cost < 1)
                                         return 0;
                  me->add("jingli", jingli_gain);
                  me->set_temp("respirate_cost", respirate_cost -= jingli_gain);
                  cost = jingli_gain*3/2;
                  if( base_name(where) == "/d/wudang/long_shiliang" ) cost = cost/3*2;
                  if( me->query_skill_mapped("force") == "taiji-shengong" )
                  {
                          write("�����ʯ����ֻ����һ����Ϣ������Ѹ��������ȫ���е��泩�ޱȡ�\n");

                          me->receive_damage("jing", cost, "�����߻���ħ����");
                          //me->receive_damage("qi", cost/10, "�����߻���ħ����");
                  }
                  else
                  {
                                if( random(6)==3 )
                                {
                                        if(me->query_skill_mapped("force") == "bitao-xuangong")
                                        {
                                          write("�����ʯ����ֻ����һ����Ϣ�����ڴ�����ȥ��������ò��Ծ����ѵ����߻���ħ��ǰ�ף�\n");
                                          cost = jingli_gain + random(jingli_gain*100);
                                        }
                                        else
                                        {
                                          write("�����ʯ����ֻ����һ����Ϣ�����ڴ�����ȥ��������ò��Ծ���\n");
                                          cost = jingli_gain + random(jingli_gain*10);
                                        }
                                        me->receive_damage("jing", cost, "�����߻���ħ����");
                                }
                                else
                                {
                                  write("�����ʯ�����ƺ��е���ᣬֻ����һ����Ϣ������Ѹ��������ȫ���е��泩�ޱȡ�\n");

                                  me->receive_damage("jing", cost, "�����߻���ħ����");
                                  //me->receive_damage("qi", cost/10, "�����߻���ħ����");
                                }

                  }

                  if (respirate_cost > 0)
                                         return 1;

                  me->set_temp("pending/exercise", 0);
                  message_vision("$N������ϣ�����˫�ۣ�վ��������\n", me);
                  if ((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
                                         return 0;
                  else {
                                         if ((int)me->query("max_jingli") > (int)me->query_skill("force") * 10) {
                                                                write("��ľ�����Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
                                                                me->set("jingli", (int)me->query("max_jingli"));
                                                                return 0;
                                         }
                                         else {
                                                                me->add("eff_jingli", 1);
                                                                me->set("jingli", (int)me->query("max_jingli"));
                                                                write("��ľ��������ˣ���\n");
                                                                return 0;
                                         }
                  }
}

int halt_respirate(object me)
{
                  if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
                                         me->set("jingli", (int)me->query("max_jingli") * 2);
                  me->set_temp("pending/respirate", 0);
                  return 1;
}

