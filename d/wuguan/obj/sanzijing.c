//by remove 16/09/2001
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�����־���", ({"sanzi jing", "jing" ,"book"}));
        set_weight(200);
        if (clonep())
            set_default_object(__FILE__);
        else
        {
            set("unit", "��");
            set("long", 
                   "�����й��Ŵ�ѧͯ�����ɶ��\n"
                   "��һҳд�ţ���֮�����Ա��ƣ��������ϰ��Զ��......\n");
            set("material", "paper");
            set("value", 200);
      }
}
void init()
{
          add_action("do_study", "study");
          add_action("do_study", "du");
}int do_study(string arg)
{
          object me = this_player();
          object ob = this_object();
          int xx = 30 - me->query("int");
          if (xx < 5 )xx =5;
          if (!id(arg)) return 0;
          if ( me->query_skill("literate", 1) <10)
            {write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");return 1;}
          if ( me->query_skill("literate", 1) >20)            
         {write("���Ѿ��޷��ӡ����־�����ѧ���κ�֪ʶ�ˡ�\n");return 1;}
          else {
        if (!present("sanzi jing", me)) return 0;
         
           if ( me->query("jing") < 20 )
          {
             write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
             return 1;
            }        if (me->is_busy())
             {
                write("��������æ���ء�\n");
                return 1;
              }        if ( me->is_fighting() )
             { 
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
              }
       message("vision", me->name() + "ҡͷ���ԣ��������дʡ�\n", environment(me), me);
         me->improve_skill("literate", random(me->query_int()));
         me->add("jing", -xx);
         write("���ж������־������ƺ�����д��Ҳ����ˡ�\n");
       return 1;
}                           
}


