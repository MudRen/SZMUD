//Cracked by Roath
// xiakedao/bingqi.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "������");
        set("long", @LONG
���������͵������������Ｘ�������������ſ��������ǵ���ǹ��
�������ȸ�ʽ���̱��С�һ������������������������������ȡ
���������е��
LONG );

      set("exits", ([
                "east" : __DIR__"yongdao5",
      ]));
        switch (random(5)) 
        {
                case 0:
                        set("objects", ([
                                "/clone/weapon/bian" : 1,
                                "/clone/weapon/zhujian" : 1,
                                "/clone/weapon/muchui" : 1,             
                                "/clone/weapon/mudao" : 1,
                        ]));
                        break;
                case 1:
                        set("objects", ([
                                "/clone/weapon/wandao" : 1,
                                "/clone/weapon/stick" : 1,
                                "/clone/weapon/mudao" : 1,            
                                "/clone/weapon/yaochu" : 1,
                        ]));
                        break;
                case 2:
                        set("objects", ([
                                "/clone/weapon/caidao" : 1,
                                "/clone/weapon/panguanbi" : 1,
                                "/clone/weapon/tiegun" : 1,             
                                "/clone/weapon/tiezhang" : 1,
                        ]));
                        break;  
        }
        set("indoors", "xiakedao" );
        set("cost", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("skill_type")=="sword") j++;
                if ((string)inv[i]->query("skill_type")=="hammer") j++;
                if ((string)inv[i]->query("skill_type")=="blade") j++;
                if ((string)inv[i]->query("skill_type")=="club") j++;
                if ((string)inv[i]->query("skill_type")=="stick") j++;
                if ((string)inv[i]->query("skill_type")=="staff") j++;
                if ((string)inv[i]->query("skill_type")=="whip") j++;
                if ((string)inv[i]->query("skill_type")=="throwing") j++;
                if ((string)inv[i]->query("id")=="coin") j--;

        }
        
        if ( j > 1 ) 
                return notify_fail("����㻹��Ϊ�������������Ⱑ�� ����������ȥ�Ķ���");

        return ::valid_leave(me, dir);
}

