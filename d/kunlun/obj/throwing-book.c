// Code of ShenZhou
#include <ansi.h>

inherit ITEM;
//  inherit F_UNIQUE;
void create()
{
        set_name(WHT"Ͷ���ؾ�"NOR, ({"throwing book", "book"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���Ǳ����ذ����飬������������ؼ�����ʹ�ð������ؾ�����\n");
                set("material", "paper");
                set("value", 500);
        }
}
void init()
{
        add_action("do_study", "du");
        add_action("do_study", "study");
}
int do_study(string arg)
{
        object me = this_player();
        object ob = this_object();

        if (!id(arg)) return 0;

        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if (!present("throwing book", me)) return 0;
            if (!present("sangmen ding", me)){
          write("��Ҫ�ҵ����ʵ��������ܱȻ���\n");
                 return 1;
          }

        if ( me->query("jing") < 35){
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }
        if (environment(me)->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }

        if ( me->is_fighting() ){ 
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if ( me->query("potential") < 1){
                write("��Ȼ���Ծ�Ǳ���Ѿ����ӵ��˼��£��������ɥ�ϵط��ֻ���û��ѧ���κζ�����\n");
                return 1;
        }

        message("vision", me->name() + "���š�Ͷ���ؾ���һ���ұȻ���\n", environment(me), me);

        me->improve_skill("mantian-huayu", random(me->query_int()*3));
        me->receive_damage("jing", 800 / (int)me->query("int"));
//        me->add("potential", random(-1));

          if(me->query_skill("mantian-huayu", 1) > 180){
          me->add("potential", random(-1));
        me->receive_damage("jing", 1200 / (int)me->query("int"));
        }
        write("��Ȼ���һ�ᡶͶ���ؾ�������������������\n");
        return 1;
}
