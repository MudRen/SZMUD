       // Code of ShenZhou 
       inherit ITEM; 
       inherit F_UNIQUE; 
       void create() 
       { 
               set_name("����ȭ��", ({"qishang jing", "jing"})); 
               set_weight(200); 
               if (clonep()) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "��"); 
                      set("long", " 
              ����֮���������� 
              �����˷δݸγ��� 
              ���뾫ʧ���㱣� 
              ������������Ƿ���\n"); 
                      set("material", "paper"); 
                     set("value", 500); 
                  set("no_get", 1);
                  set("no_give", 1);
                  set("no_drop", 1);
                  set("no_steal", 1);
              } 
              ::create(); 
     } 
      void init() 
      { 
             add_action("do_study", "du"); 
              add_action("do_study", "study"); 
              add_action("do_steal", "steal");
       } 
     int do_steal(string arg)
      {
      if ( !arg || arg == "jing" ) return 0; 
           write("͵���˵�����ȭ����С����������\n"); 
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
       
              if (!present("qishang jing", me)) return 0; 
       
              if ( me->query_skill("cuff", 1) < me->query_skill("qishang-quan",1)*2/3){ 
                      write("��Ļ���ȭ����򲻹���\n"); 
              return 1; 
              } 
              if ( me->query_skill("qishang-quan",1) > 100 ) { 
                      write("����þ������߹��ڴ�ǳ���޷���ѧ���¶����ˡ�\n"); 
                      return 1; 
              } 
              if ( me->query("jing") < 60){ 
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
                      write("���Ǳ�ܲ�����\n"); 
                      return 1; 
              } 
       
              message("vision", me->name() + "��ϸ���ж�������ȭ������\n",environment(me), me); 
       
              me->improve_skill("qishang-quan", random(me->query_int()*3/2)); 
              me->receive_damage("jing", 1500 / (int)me->query("int")); 
              me->add("potential", -1); 
              me->apply_condition("qs_self_damage", 5+random(5)); 
       
              write("���ж�������ȭ�����������ĵá�\n"); 
              return 1; 
      } 
