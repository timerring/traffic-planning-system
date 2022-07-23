#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
using namespace std;

#define ALLNameNum 99
#define INF 99999

typedef int dist[ALLNameNum];
typedef int path[ALLNameNum];

typedef struct
{
	char name[50];
	char intro[999];
	int  x, y;
}SITE;

typedef struct
{
	SITE site[ALLNameNum];
	int length[ALLNameNum][ALLNameNum];
}MAP;

MAP M;
int N = 0;
path p;
dist d;

void init()
{
	int i, j;
	strcpy(M.site[1].name, "胶东机场");
	strcpy(M.site[1].intro, "青岛胶东国际机场（Qingdao Jiaodong International Airport），位于中国山东省青岛市胶州市胶东街道前店口村");
	strcpy(M.site[2].name, "红岛火车站");
	strcpy(M.site[2].intro, "山东省青岛市城阳区红岛经济区河套街道汇海路南侧");
	strcpy(M.site[3].name, "流亭");
	strcpy(M.site[3].intro, "青岛流亭国际机场（已关闭）");
	strcpy(M.site[4].name, "青岛站");
	strcpy(M.site[4].intro, "山东省青岛市市南区泰安路2号");
	strcpy(M.site[5].name, "青岛北站");
	strcpy(M.site[5].intro, "山东省青岛市李沧区静乐路1号");
	strcpy(M.site[6].name, "李村");
	strcpy(M.site[6].intro, "李村隶属于山东省青岛市李沧区");
	strcpy(M.site[7].name, "五四广场");
	strcpy(M.site[7].intro, "五四广场（May Fourth Square），位于山东省青岛市市南区东海西路");
	strcpy(M.site[8].name, "中山公园");
	strcpy(M.site[8].intro, "青岛最大的综合性公园");
	strcpy(M.site[9].name, "麦岛");
	strcpy(M.site[9].intro, "麦岛是山东省青岛市区沿岸第一大岛");
	strcpy(M.site[10].name, "中心医院");
	strcpy(M.site[10].intro, "青岛市中心医院，青岛市中心医院位于山东省青岛市四方区四流南路127号");
	strcpy(M.site[11].name, "QAU");
	strcpy(M.site[11].intro, "青岛农业大学（Qingdao Agricultural University），位于山东省青岛市");
	strcpy(M.site[12].name, "台东");
	strcpy(M.site[12].intro, "台东区是山东省青岛市原辖区，地名沿用自原区划台东镇。");
	strcpy(M.site[13].name, "遵义路");
	strcpy(M.site[13].intro, "山东省青岛市李沧区");
	strcpy(M.site[14].name, "鳌山卫");
	strcpy(M.site[14].intro, "鳌山卫镇位于即墨市东隅,镇机关驻地距即墨市政府所在地20公里。");
	strcpy(M.site[15].name, "苗岭路");
	strcpy(M.site[15].intro, "苗岭路站（Miaoling Rd Station），位于中国山东省青岛市深圳路与苗岭路交叉口南侧");
	strcpy(M.site[16].name, "SDU");
	strcpy(M.site[16].intro, "山东大学（青岛）位于山东省青岛市即墨区“蓝色硅谷”核心区");
	strcpy(M.site[17].name, "OUC");
	strcpy(M.site[17].intro, "中国海洋大学（Ocean University of China，OUC），位于山东省青岛市");
	for (i = 1; i <= ALLNameNum; i++)
	{
		for (j = 1; j <= ALLNameNum; j++)
		{
			M.length[i][j] = INF;
		}
	}
	for (i = 1; i <= ALLNameNum; i++)
		M.length[i][i] = 0;
	M.length[1][2] = M.length[2][1] = 30;
	M.length[1][3] = M.length[3][1] = 30;
	M.length[2][3] = M.length[3][2] = 90;
	M.length[2][4] = M.length[4][2] = 70;
	M.length[3][5] = M.length[5][3] = 50;
	M.length[3][6] = M.length[6][3] = 50;
	M.length[4][5] = M.length[5][4] = 50;
	M.length[4][7] = M.length[7][4] = 100;
	M.length[5][6] = M.length[6][5] = 30;
	M.length[6][7] = M.length[7][6] = 110;
	M.length[6][10] = M.length[10][6] = 20;
	M.length[7][8] = M.length[8][7] = 30;
	M.length[7][9] = M.length[9][7] = 30;
	M.length[7][10] = M.length[10][7] = 30;
	M.length[8][9] = M.length[9][8] = 30;
	M.length[9][10] = M.length[10][9] = 60;
	M.length[9][11] = M.length[11][9] = 40;
	M.length[10][11] = M.length[11][10] = 40;
	M.length[11][12] = M.length[12][11] = 100;
	M.length[11][13] = M.length[13][11] = 50;
	M.length[12][13] = M.length[13][12] = 60;
	M.length[12][15] = M.length[15][12] = 30;
	M.length[12][17] = M.length[17][12] = 170;
	M.length[13][14] = M.length[14][13] = 70;
	M.length[13][15] = M.length[15][13] = 30;
	M.length[13][16] = M.length[16][13] = 50;
	M.length[14][16] = M.length[16][14] = 50;
	M.length[15][16] = M.length[16][15] = 20;
	M.length[16][17] = M.length[17][16] = 30;
	N = 17;
	M.site[1].x = 50;
	M.site[1].y = 25;
	M.site[2].x = 150;
	M.site[2].y = 125;
	M.site[3].x = 250;
	M.site[3].y = 25;
	M.site[4].x = 150;
	M.site[4].y = 475;
	M.site[5].x = 350;
	M.site[5].y = 175;
	M.site[6].x = 475;
	M.site[6].y = 50;
	M.site[7].x = 475;
	M.site[7].y = 475;
	M.site[8].x = 575;
	M.site[8].y = 650;
	M.site[9].x = 675;
	M.site[9].y = 525;
	M.site[10].x = 575;
	M.site[10].y = 150;
	M.site[11].x = 750;
	M.site[11].y = 225;
	M.site[12].x = 575;
	M.site[12].y = 525;
	M.site[13].x = 575;
	M.site[13].y = 225;
	M.site[14].x = 1075;
	M.site[14].y = 25;
	M.site[15].x = 1000;
	M.site[15].y = 375;
	M.site[16].x = 1100;
	M.site[16].y = 225;
	M.site[17].x = 1175;
	M.site[17].y = 325;
}

void scsysite()
{
	int t;
	printf("所有地点如下：\n");
	for (t = 1; t <= N; t++)
	{
		printf("编号：%d\n   地点：%s\n   介绍：%s\n", t, M.site[t].name, M.site[t].intro);
	}
	printf("\n任意键返回");
	getch();
}

void zengj()
{
	char s1[30], s2[200];    //地点名称；地点介绍 
	int t, i, q, p, x, y;       //t为与该地点共有几个地点相连；i为应第几个地点与之相连；
							//q为与之相连的地点；p为这个地点和新地点的距离 
							//x为此地点位置的x值；y为此地点位置的y值 
	N++;
	printf("请输入该地点的名称：");
	scanf("%s", &s1);
	printf("请输入该地点的介绍：");
	scanf("%s", &s2);
	printf("请输入该地点的位置的x值：");
	scanf("%d", &x);
	printf("请输入该地点的位置的y值：");
	scanf("%d", &y);
	strcpy(M.site[N].name, s1);
	strcpy(M.site[N].intro, s2);
	M.site[N].x = x;
	M.site[N].y = y;
	printf("请输入共有几个地点与此地点相通：");
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		printf("第%d个地点与之相通；", i);
		scanf("%d", &q);
		printf("他们之间的距离为：");
		scanf("%d", &p);
		M.length[N][q] = M.length[q][N] = p;
	}
	printf("\n按任意键返回！");
	getch();
}

void delSite()
{
	printf("请输入要删除的地点序号数");
	int t, p, Q;
	scanf("%d", &p);
	Q = p;
	if (p <= N)
	{//N节点数量
		for (t = 1; t <= N; t++)
			for (p = p; p <= N; p++)
			{
				M.length[t][p] = M.length[t][p + 1];
				M.length[p][t] = M.length[p + 1][t];
			}
		for (Q; Q < N; Q++)
			M.site[Q] = M.site[Q + 1];
		printf("删除成功");
	}
	else
		printf("删除失败");
	N--;
	printf("\n按任意键返回！");
	getch();
}

void gxsite()
{
	int t;
	char s1[30], s2[200];
	printf("请输入要更新的地点编号：");
	scanf("%d", &t);
	if (t > N)
		printf("此地点不存在，更新失败");
	else
	{
		printf("请输入地点名称：");
		scanf("%s", &s1);
		printf("请输入地点介绍：");
		scanf("%s", &s2);
		strcpy(M.site[t].name, s1);
		strcpy(M.site[t].intro, s2);
		printf("更新完成！");
	}
	printf("\n按任意键返回！");
	getch();
}

void zengjl()
{
	int a, b, c;
	printf("请问要在那两个地点之间增加一条路\n");
	printf("请输入第一个地点编号：");
	scanf("%d", &a);
	printf("请输入第二个地点编号：");
	scanf("%d", &b);
	printf("请输入这条路的长度：");
	scanf("%d", &c);
	if (a > N || b > N)
		printf("地点超出了已有地点范围，路径增加失败！");
	else
	{
		M.length[a][b] = M.length[b][a] = c;
		printf("路径增加成功！");
	}
	printf("\n按任意键返回！");
	getch();
}

void delpath()
{
	int a, b;
	printf("删除路径的编号\n");
	printf("请输入第一个地点编号：");
	scanf("%d", &a);
	printf("请输入第二个地点编号：");
	scanf("%d", &b);
	if (a > N || b > N)
		printf("越界，路径删除失败！");
	else
	{
		M.length[a][b] = M.length[b][a] = INF;
		printf("路径删除成功！");
	}
	printf("\n按任意键返回！");
	getch();
}

void gxl()
{
	int a, b, c;
	printf("请问要更新那两个地点之间的路\n");
	printf("请输入第一个地点编号：");
	scanf("%d", &a);
	printf("请输入第二个地点编号：");
	scanf("%d", &b);
	printf("请输入更新后的长度：");
	scanf("%d", &c);
	if (a > N || b > N)
		printf("这条路不存在，路径更新失败！");
	else
	{
		M.length[a][b] = M.length[b][a] = c;
		printf("路径更新成功！");
	}
	printf("\n按任意键返回！");
	getch();
}

void cxsite()
{
	int a;
	printf("请问您要查询的地点编号是：");
	scanf("%d", &a);
	if (a > N)
		printf("查询的地点不存在，查询失败！");
	else
		printf("编号：%d\n   地点：%s\n   介绍：%s\n", a, M.site[a].name, M.site[a].intro);
	printf("\n按任意键返回！");
	getch();
}

void dijkstraAllSite()
{
	int v0;
	printf("请输入查询的地点：");
	scanf("%d", &v0);
	boolean flag[ALLNameNum];
	//v表示上一个节点，k表示遍历节点
	int i, k, j, v, min, x;
	for (v = 1; v <= N; v++)
	{
		flag[v] = FALSE;
		d[v] = M.length[v0][v];
		if (d[v] < INF && d[v] != 0)
			p[v] = v0;
		else
			p[v] = -1;
	}
	flag[v0] = TRUE;
	d[v0] = 0;//原点距离
	for (i = 2; i <= N; i++)
	{
		min = INF;
		for (k = 1; k <= N; ++k)
			if (!flag[k] && d[k] < min)
			{//没有被查询过并且距离小于最小值则更新
				v = k;
				min = d[k];
			}

		if (min == INF)
			return;
		flag[v] = TRUE;
		for (k = 1; k <= N; ++k)
			if (!flag[k] && (min + M.length[v][k] < d[k]))
			{
				d[k] = min + M.length[v][k];//到k的距离
				p[k] = v;//k节点的上一个节点是v
			}
	}
}

void printAllSite()
{
	int st[ALLNameNum], i, pre, top = -1;
	for (i = 1; i <= N; i++)
	{
		printf("\n到达地点%2d的总距离为: %5d , 经过路径为:", i, d[i]);
		st[++top] = i;
		pre = p[i];
		while (pre != -1)
		{
			st[++top] = pre;
			pre = p[pre];
		}
		while (top > 0)
		{
			printf("%d", st[top--]);
			if (top > 0)
				printf("--->");
		}
	}
	getch();
}

void dijkstraTwoSite()
{
	int v0;
	printf("请输入起始地点：");
	scanf("%d", &v0);
	boolean flag[ALLNameNum];
	int i, k, j, v, min, x;
	for (v = 1; v <= N; v++)
	{
		flag[v] = FALSE;
		d[v] = M.length[v0][v];
		if (d[v] < INF && d[v] != 0)
			p[v] = v0;
		else
			p[v] = -1;
	}
	flag[v0] = TRUE;
	d[v0] = 0;
	for (i = 2; i <= N; i++)
	{
		min = INF;
		for (k = 1; k <= N; ++k)
			if (!flag[k] && d[k] < min)
			{
				v = k;
				min = d[k];
			}

		if (min == INF)
			return;
		flag[v] = TRUE;
		for (k = 1; k <= N; ++k)
			if (!flag[k] && (min + M.length[v][k] < d[k]))
			{
				d[k] = min + M.length[v][k];
				p[k] = v;
			}
	}
}

void printTwoSite()
{
	int y;
	printf("\n请输入目的地点：");
	scanf("%d", &y);
	int st[ALLNameNum], i, pre, top = -1;
	for (i = 1; i <= N; i++)
	{
		if (i == y)
			printf("\n总距离是: %5d , 经过路径为:", d[i]);
		st[++top] = i;
		pre = p[i];
		while (pre != -1)
		{
			st[++top] = pre;
			pre = p[pre];
		}
		while (top > 0)
		{
			if (i == y)
			{
				printf("%d", st[top--]);
				if (top > 0)
					printf("--->");
			}
			else
				top--;
		}
	}
	getch();
}

void scdt()
{
	int i, j;
	char s[100];
	strcpy(s, "交通地图");
	initgraph(1200, 800);
	for (i = 1; i <= N; i++)
	{
		setfillcolor(RGB(225, 236, 0));
		fillcircle(M.site[i].x, M.site[i].y, 20);
		outtextxy(M.site[i].x, M.site[i].y, LPCTSTR(M.site[i].name));
	}
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
		{
			if (M.length[i][j] > 0 && M.length[i][j] < 1000)
				line(M.site[i].x, M.site[i].y, M.site[j].x, M.site[j].y);
		}
	outtextxy(900, 650, LPCTSTR(s));
	getch();
	closegraph();
}



main()
{
	init();
	int x;
	while (1)
	{
		printf("**********************************************************************\n");
		printf("*                 欢迎使用基于交通路线的规划系统                     *\n");
		printf("**********************************************************************\n");
		printf("\n                     0、退出程序            ");
		printf("\n                     1、输出所有地点及其介绍");
		printf("\n                     2、查询某一个地点及其介绍");
		printf("\n                     3、增加一个地点");
		printf("\n                     4、删除一个地点");
		printf("\n                     5、更新一个地点");
		printf("\n                     6、增加一条路");
		printf("\n                     7、删除一条路");
		printf("\n                     8、更新一条路");
		printf("\n                     9、查询某一地点到其他所有地点的最短路径");
		printf("\n                    10、查询某两个地点之间的最短路径   ");
		printf("\n                    11、输出地图                       目前地点数：%d\n", N);
		printf("请输入选项：");
		scanf("%d", &x);
		if (x == 0)
			break;
		else
			switch (x)
			{
			case 1:scsysite(); break;
			case 2:cxsite(); break;
			case 3:zengj(); break;
			case 4:delSite(); break;
			case 5:gxsite(); break;
			case 6:zengjl(); break;
			case 7:delpath(); break;
			case 8:gxl(); break;
			case 9:dijkstraAllSite(); printAllSite(); break;
			case 10:dijkstraAllSite(); printTwoSite(); break;
			case 11:scdt(); break;
			}
		system("cls");
	}
}
