#include <ansi.h>
       inherit ITEM; 

       void create() 
       { 
               set_name(HIW"������"NOR, ({ "box", "he" }) ); 
               set_weight(10); 
                      set("unit", "��"); 
                      set("long", "һ�����ص������С�\n��˵�����޵�ǰ�����������µģ��Ͽ�򿪣�opem���ɡ�����\n"); 
                      set("value", 0); 
                      set("material", "wood"); 
                      set("no_drop", "�������صĶ�����ô������Ҷ��ء�\n"); 
                      set("no_get", "�������������뿪�Ƕ���\n"); 
                      set("no_give", 1); 

              setup(); 
      } 

      void init() 
             {add_action("do_open", "open");       }

      int do_open(string arg) 
      { 
             object me = this_player(); 
object obj;
int i;

             if (me->query("family/family_name")!= "������")
{write(HIG"��������У����洫��һ���Ϲֵļ�������ʮ��������\n���ܲ�����������ɤ�ӵĴ̼�����æ����������ӡ�\n"NOR); 
destruct(this_object()); 
return 1;
}


if (me->query_skill("pixie-jian",1)>200)
{
for (i=0;i<20;i++) {obj = new("/d/changbai/obj/yinyang-cao.c");obj->move(me);}
write(HIG"��������У����洫��һ��������������ָ��Ѱ��һ��ϡ���Ĳ�ҩ��\n����ϸһ����������������Ҫ��ҩ���ӣ�����ϲ�����⡣\n"NOR);  
destruct(this_object());
return 1;
}

write(HIM"��������У����洫������Ϥ��������ԭ���������˴��ڻ�������������ϰ�ؾ��ļ�¼��\n��Ͻ������������ļǣ������ϸ�����һ�������ֶ��Լ����������д������档\n"NOR);
write(HIM"����˼����ȫ�������ˣ��ͰѺ�������һ���ˡ�\n"NOR);
me->improve_skill("poison",20000);
me->improve_skill("poison",20000);
me->improve_skill("poison",20000);

destruct(this_object());
return 1;
}
