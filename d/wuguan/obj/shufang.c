//by remove 16/09/2001
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("��ǧ���ġ�", ({"qianzi wen", "shu", "book"}));
        set_weight(200);
        if (clonep())
            set_default_object(__FILE__);
        else
        {
            set("unit", "��");
            set("long", 
                 "��ǧ���ġ�\n"                 "�������Ա��ɢ�����ɡ������á�׫\n");
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
          if (!id(arg)) return 0;
         if ( me->query_skill("literate", 1) <10)
         return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
           if (me->query_skill("literate", 1) >40)            
           return notify_fail("���Ѿ��޷��ӡ�ǧ���ġ���ѧ���κ�֪ʶ�ˡ�\n");
          else {
        if (!present("qianzi wen", me)) return 0;
         
           if ( me->query("jing") < 30 )
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
       message("vision", me->name() + "�������������ƣ������ģ�����ӯ꾣��������š�\n", environment(me), me);
         me->improve_skill("literate", random(me->query_int()*3/2));
         me->add("jing", -30);
         write("��������ǧ���ġ����ƺ�����д��Ҳ����ˡ�\n");
       return 1;
}                           
}






