//blacko

inherit ROOM;

void create()
{
        set("short","ͬ�����ּ��Ϻ�");

        set("long",@LONG
������ȫ��������ͬ�����Ϻţ���λ�ڱ���סǰ�����դ����ͬ����֮��
����ȡ��ͬ���ʵ£�����������֮�⡣�˵����������������ʷ���ּ�������
Ӫ�͹�������濴��ȥ��Щ�¾ɴ�����������δ���Ե�����˲��ݵĳ���
����ۣ������濴��ȥ���Կ���һ����ͷ���к����ˡ�
LONG);

        set("exits",([ "enter" : __DIR__"/newjob/doctor/tongren",
                  
                      ])
           );
          set("cost",1);

          set("objects",([
                "/newjob/doctor/npc/xianyang" : 1,
          ]));


        setup();

}